#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define array ar

typedef long long ll;

vector<vector<int>>dp(100000, vector<int>(2));

int solve(int r, int c){
	if(r==0 || c==0) return 0;
	if(r==1 and c==1) return 1;
	if(dp[r][c]!=0) return dp[r][c];
	int t = solve(r-1,c) + solve(r,c-1);
	dp[r][c] = t;
	return t;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin>>t;
	while(t--){
		int r,c;
		cin>>r>>c;
		cout<<r<<" "<<c;
		cout<<" "<<solve(r,c)<<endl;
		for(int i=0; i< 100000; i++){
			for(int j=0; j< 2; j++){
				dp[j].clear();
			}
		}
	}
	
	return 0;
}