#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define ar array
typedef long long ll;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n; cin>>n;
	int m; cin>>m;

	vector<ar<int, 2>> mines;
	vi vy;

	while(m--){
		int x,y; cin>>x>>y;
		mines.pb({x,y});
		vy.pb(y);
	}




	return 0;
}