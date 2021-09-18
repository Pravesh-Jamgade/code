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

bool comp(int l, int r, vi& v){
	if(v[l]>=v[r]) return true;
	return false;
}

void solve(){

	int n; cin>>n;

	vi v(n,0);
	for(int i=0; i< n; i++){
		cin>>v[i];
	}

	if(n==1){
		cout<<v[0]<<" "<<0;
		return;
	}

	

	int l,r; l=0; r=v.size()-1;
	int ls,rs; ls=rs=0;
	bool turn = 1;
	while(l<=r){
		if(turn){
			if(comp(l,r,v)){
				ls+=v[l++];
			}else ls+=v[r--];
			turn=0;
		}else{
			if(comp(l,r,v)){
				rs+=v[l++];
			}else rs+=v[r--];
			turn=1;
		}
	}

	cout<<ls<<" "<<rs<<endl;

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	#elif ONLINE_JUDGE
	solve();
	#endif

	return 0;
}