#include<bits/stdc++.h>
using namespace std;
/*input
3 50
100,120,60
20,30,10

complex: O(N*W) 
*/
#define fi first
#define se second
typedef pair<int, int> pii;

const int mxN =1e3;
vector<int>p,w;
vector<pii> wp;

int main(){
	freopen("input.txt", "r", stdin);

	int n, w;
	cin>>n>>w;

	int q=2;
	while(q--){
		string s; getline(cin,s);

		stringstream ss;
		ss << s;

		int tmp; char  c;
		while(ss>>tmp){
			ss>>c;
			if(q==1) p.push_back(tmp);
			if(q==0) w.push_back(tmp);
		}

		for(int i=0; i<n; i++){
			wp.push_back({w[i], p[i]});
		}

		sort(wp.begin(), wp.end());

		p.clear(); 
		for(auto e: wp){
			w.push_back(e.fi);
			p.push_back(e.se);
		}

		
	}

	return 0;
}