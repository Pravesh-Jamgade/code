#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back


const int mxN = 1e6;
typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int n; cin>>n;
	
	int dp[mxN];

	dp[0] = 0;
	for(int i=1; i<=n; ++i){
		dp[i]=1e9;
		int x = i;
		while(x){
			dp[i] = min(dp[i], dp[i - x%10] + 1);
			x=x/10;
		}
	}

	cout<<dp[n];

	return 0;
}