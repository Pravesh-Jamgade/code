#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
/*input
10 5
10 9 1 2 3 4 5 6 7 8
*/
int main(){

	freopen("input.txt", "r", stdin);
	ll n,k;
	cin>>n>>k;

	vector<ll> p;
	for(int i=0; i< n; i++){
		int tx; cin>>tx;
		p.push_back(tx);
	}

	//prefix array
	ll a[n] = {0};

	a[0] = p[0];
	for(int i=1; i< n; i++){
		a[i] = a[i-1] + p[i];
	}

	ll mxN = INT_MIN;
	for(int i=0; i< k; i++){
		ll sum = a[i] + a[n-1] - a[n-k+i];
		if(mxN<sum)
			mxN = sum;
	}

	cout<<mxN<<endl;


	return 0;
}