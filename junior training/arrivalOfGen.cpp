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
	vector<ar<int,2>> v;
	for(int i=0; i< n; i++){
		int k; cin>>k;
		v.pb({k,i});
	}


	return 0;
}