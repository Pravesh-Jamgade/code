#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back


typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int n,x; cin>>x>>n;
	vector<int> v(n, 0);
	for(int i=0; i< n; i++)
		cin>>v[i];

	v.pb(x);
	int ans, mx;
	ans = mx = 0;

	for(int i=1; i<= n; i++){
		int t = abs(v[i]-v[i-1]);
		cout<<t<<" ";
	}
	cout<<ans;

	return 0;
}