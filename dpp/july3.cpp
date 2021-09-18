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


vi solve(vi& v, int k, int x){
	vi res;
	int t=1e3;
	int it=0;
	vi u=v;
	for(int i=0; i< v.size(); i++){
		v[i]= abs(v[i]-x);
		if(v[i]<t){
			it=i;
			t=v[i];
		}
	}
	// cout<<it<<endl;
	// for(auto e: v){
	// 	cout<<e<<" ";
	// }
	// cout<<endl;

	// for(auto e: u){
	// 	cout<<e<<" ";
	// }
	// cout<<endl;

	int l,r;
	l=r=it; r++;
	while(k--){
		if(l<0) break;
		if(r>=v.size()) break;
		if(v[l] <= v[r] and u[l] < u[r]){
			res.pb(u[l--]);
		}
		else{
			res.pb(u[r++]);
		}
	}

	for(int i=l; i>=0 and k>=0; --k,--i){
		res.pb(u[i]);
	}

	for(int j=r; j< v.size() and k>=0; --k,++j){
		res.pb(u[j]);
	}

	sort(res.begin(), res.end());

	// for(auto e: res) cout<<e<<" ";


	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int k,x; cin>>k>>x;
	string in; cin>>in;

	vi v;
	stringstream ss;
	ss << in;

	int t;
	while(ss>>t){
		char c; ss>>c;
		v.pb(t);	
	}

	vi vec = solve(v,k,x);
	for(auto e: vec) cout<<e<<" ";
	
	return 0;
}