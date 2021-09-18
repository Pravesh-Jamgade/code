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

const int mod = 1e9+7;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int t; cin>>t;
	while(t--){
		vector<ll> inp(3,0);
		for(int i=0; i< 3; i++){
			cin>>inp[i];
		}

		sort(inp.begin(), inp.end());
		ll ans = 1;
		for(int i=0; i< 3; i++){
			ans = (ans*((inp[i]- i)%mod))%mod ;
		}

		cout<<ans<<endl;
		

	}

	return 0;
}