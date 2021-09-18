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

vector<int> dp(1000, -1);

bool solve(int a, int s, vi& v){
	if(s<0) return false;
	if(s==0) return true;

	for(int i=a; i< v.size(); i++){
		if(dp[s-v[i]]==0) {
			dp[s-v[i]] = false;
			continue;
		}
		if(solve(i+1, s-v[i], v) || dp[s-v[i]]==1){
			dp[s]=1;
			return true;
		}
		else dp[s]=0;
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	int s;
	cin>>s;

	cin.ignore();

	vi v;
	string str;
	getline(cin,str); 

	stringstream ss;
	ss<<str;

	int t; char c;
	while(ss>>t){
		v.pb(t);
	}

	cout<<solve(0, s, v);

	return 0;
}