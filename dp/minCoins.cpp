#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back

typedef long long ll;

int solve(int sum, vector<int>& coins){
	vector<int> dp(sum+1, INT_MAX);
	dp[0] = 0;
	for(int i=1; i<= sum; i++){
		for(int j=0; j< coins.size(); j++){
			if(i<coins[j]) continue;
			dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
		}
	}

	if(dp[sum] == INT_MAX) cout<<-1;
	else cout<<dp[sum]<<endl;
	return 0;
}

int main(){
	
	freopen("input.txt", "r", stdin);
	
	int n,x;
	cin>>n>>x;

	vector<int> c; 
	c.resize(n);
	
	for(int i=0; i< n; i++)
		cin>>c[i];

	for(auto e: c) 
		cout<<e<<" ";
	cout<<endl;

	solve(x, c);

	return 0;
}