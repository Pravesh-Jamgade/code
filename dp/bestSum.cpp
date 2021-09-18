#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define po pop_back
#define pii pair<int,int>
#define array ar


typedef long long ll;

int mN = 1e3;

vi minV;
bool solve(vi& v, int s, int d, vi& cur){

	if(s<0) return false;
	if(s==0) return true;

	for(int i=0; i< v.size(); i++){
		int t=d;
		cur.pb(v[i]);
		if(solve(v,s-v[i],d+1,cur)){
			if(mN>d){
				mN=d;
				minV=cur;
			}
		}
		cur.po();
		d=t;
	}

	
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	int n; cin>>n;
	string in; getline(cin, in);

	vi v;
	stringstream ss; ss<<in;
	int tmp;
	while(cin>>tmp){
		v.pb(tmp);
	}

	
	vi cur; int d=0;
	solve(v,n,d,cur);

	for(auto e: minV){
		cout<<e<<" ";
	}
	cout<<endl;
	cout<<mN<<endl;

	return 0;
}