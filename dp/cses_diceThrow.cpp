#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back


typedef long long ll;

int solve(int n, int ans){
	if(n<0) return 0;
	if(n==0 || n==1) return 1;
	for(int i=1; i<= n; i++){
		int m = solve(n-i, ans);
		ans += m;
	}
	return ans;
}

int main(){
	
	freopen("input.txt", "r", stdin);
	int n, ans;
	ans = 0;
	cin>>n;
	cout<<solve(n, ans);
	return 0;
}