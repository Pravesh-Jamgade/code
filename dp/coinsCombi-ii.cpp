#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back

typedef long long ll;

void solve(int n, int sum, vector<int>& coins){
	vector<int> dp(sum+1, 0);

	dp[0] = 1;
	for(int i=1; i<= sum; i++){
		for(int j=0; j< n; j++){
			if(i<coins[j]) continue;
			int t = coins[j];
			if(t%coins[j] == 0) dp[i]+=1;
		}

		int t = i;
		for(int k=0; t!=0 and k<n; k++){
			t = t%coins[k];
		}
		if(t==0)
			dp[i]++;
	}
	cout<<"no repeat permutation for sum: "<<sum<<endl;
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