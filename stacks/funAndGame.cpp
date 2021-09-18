#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	freopen("input.txt", "r", stdin);
	ll n; cin>>n;

	vector<ll> p(n, 0);
	for(ll i=0; i< n; i++){
		cin>>p[i];
	}

	ll l,r; l = 0; r = n-1;

	while(l< n and r>-1){
		if(p[l] > p[r]){
			cout<<'1'<<' '; l++;
		}
		else if(p[l] < p[r]){
			cout<<'2'<<' '; r--;
		}
		else{
			cout<<'0'<<' '; l++, r--;
		}
	}


	return 0;
}