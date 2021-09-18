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

int solve1(int n){
	if(n<=2) return 1;
	return solve1(n-1) + solve1(n-2);
}

int solve2(int n){
	static vector<int> a(1000, -1);
	if(a[n]>0) return a[n];
	if(n<=2) return 1;
	int t = solve2(n-1) + solve2(n-2);
	a[n]=t;
	return a[n];
}

int solve3(int n){
	vector<int> v(100, 0);
	v[0]=v[1]=1;
	for(int i=2; i< n; i++){
		v[i]=v[i-1] + v[i-2];
	}
	return v[n-1];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		cout<<solve2(n)<<endl;
	}
	
	return 0;
}