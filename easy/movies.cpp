#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define ar array
/*Input:
3
3 5
4 9
5 8*/
typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int n; cin>>n;

	vector<ar<int,2>> t;

	for(int i=0; i< n; i++){
		int x,y; cin>>x>>y;
		t.pb({y,x});
	}

	sort(t.begin(), t.end());

	int ans, c;
	ans = c = 0;
	for(int i=1; i< t.size(); i++){
		if(t[i-1][1] <= t[i][0]){
			c++;
		}
	}	

	cout<<c<<endl;
	return 0;
}