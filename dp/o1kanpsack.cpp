#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
/*input
3 50
100,120,60
20,30,10

complex: O(N*W) 
*/

vector<int> a,b;
vector<pii> wp;
vector<vector<int>> K;

int k1(int n , int W){

	vector<int>m(W, 0);
	K.resize(n+1, m);

	for(int i=0; i<= n; i++){
		for(int j=0; j<= W; j++){
			if(i==0 || j==0){
				K[i][j] = 0;
			}
			else if(a[i-1] <= j){

				K[i][j] = max(
					b[i-1]+K[i-1][j - a[i-1]],
					K[i-1][j]
				);
			}
			else{
				K[i][j] = K[i-1][j];
			}
		}
	}
	cout<<'\n';
	for(int i=0; i< n; i++){
		for(int j=0; j<= W; j++)
			cout<<K[i][j]<<" ";
		cout<<endl;
	}
	return K[n][W];

}

int main(){
	freopen("input.txt", "r", stdin);

	int n, w;
	cin>>n>>w;

	cin.ignore();
	int q = 2;
	while(q--){
		string w; getline(cin, w);
		stringstream ss;
		ss << w;

		int tmp; char c;
		while(ss>>tmp){
			if(q == 1) a.push_back(tmp); // profit
			else if(q == 0)b.push_back(tmp); // wt
			ss>>c;
		}

	}

	for(int i=0; i< n; i++){
		wp.push_back({b[i], a[i]});// wt and profit
	}

	
	a.clear(); b.clear();
	sort(wp.begin(), wp.end());
	cout<<w<<endl;
	for(auto e: wp){
		a.push_back(e.fi); // wt
		b.push_back(e.se); // profit
		cout<<e.fi<<" "<<e.se<<endl;
	}
	cout<<k1(n, w);
	return 0;
}