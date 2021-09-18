#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define array ar


typedef long long ll;

vector<int> dp;

bool solve( int n, vi& v, vi& ans,  vii& res){

	if(n==0) return true;
	if(n<0) return false;
	for(int i=0; i< v.size(); i++){
		if(dp[i] == 0) continue;
		else{
			if(dp[n-v[i]]==1 || solve( n-v[i], v, ans, res)){
				dp[n]=dp[n-v[i]]=1;
				ans.pb(v[i]);
				if(dp[n] == 1) return true;
			}
		}
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n; 
	cin>>n; 
	cin.ignore();

	vi v;
	string in;
	getline(cin, in); 

	stringstream ss; 
	ss<<in;

	int t;
	while(ss>>t){
		char c; ss>>c;
		v.pb(t);
	}

	vi ans;
	
	dp.resize(1000, -1);

	vii res;
	
	dp[0] = 1;

	solve(n,v,ans,res);
	for(int i: ans) cout<<i<<" ";

	cout<<endl;
	ans.clear();

	for(int i=0; i< v.size(); i++){
		if(solve( n-v[i], v, ans, res)){
			ans.pb(v[i]);
			res.pb(ans);
			ans.clear();
		}
	}

	for(auto row: res){
		for(auto e: row){
			cout<<e<<" ";
		}cout<<endl;
	}

	return 0;
}