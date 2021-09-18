#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back

/*input
3 9
2 3 5
*/
typedef long long ll;

void solve(int n, int sum, vector<int>& coins){
	vector<int>dp(sum+1, 0);
	for(int i=0; i< sum+1; i++) 
		dp[i] = 0;

	dp[0] = 1;
	for(int i=1; i<= sum; i++){
		for(int j=0; j< n; j++){
			if(coins[j] > i) continue;
			dp[i]=dp[i] + dp[i - coins[j]];
		}
	}

	cout<<"total combination for sum:"<<sum<<endl;
	cout<<dp[sum]<<endl;
}
int main(){
	
	freopen("input.txt", "r", stdin);
	int n,x;
	cin>>n>>x;

	vector<int> coins(n, 0);
	for(int i=0; i< n; i++){
		cin>>coins[i];
	}

	for(auto e: coins) 
		cout<<e<<" ";

	solve(n,x,coins);
	return 0;
}