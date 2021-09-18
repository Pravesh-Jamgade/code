#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back


typedef long long ll;
const int mxN = 1e3;
int dp[mxN] = {-1};

int minF(int a, int b, int c){
	if(a>b){
		if(b>c) return c;
		else return b;
	}else{
		if(a>c) return c;
		else return a;
	}
}

int solve(int n){
	if(n<=1) return 0;
	
	if(dp[n]>-1) return	dp[n];

	if(n%3==0){
		n=n/3;
	}
	else if(n%2 == 0){
		n=n/2;
	}
	else n=n-1;
	dp[n]=1+ solve(n);
	return dp[n];
}

int main(){
	
	freopen("input.txt", "r", stdin);
	int n; cin>>n;

	int stp = 0;

	for(int i=0; i<= n; i++)
		dp[i]=-1;

	for(int i=1; i<= n; i++){
		cout<<i<<" steps: "<<solve(i)<<endl;
	}
	
	return 0;
}