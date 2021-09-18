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
	
	freopen("input.txt", "r", stdin);
	int n; cin>>n;
	set<ar<int,2>> s;

	for(int i=0; i< n; i++){
		int x,y; cin>>x>>y;
		s.insert({x, 1});
		s.insert({y, -1});
	}

	int ans,c; ans=c=0;
	for(auto e: s){
		c+=e[1];
		ans=max(ans,c);
	}

	for(auto e: s){
		cout<<e[0]<<" = "<<e[1]<<endl;
	}

	cout<<ans<<endl;

	return 0;
}