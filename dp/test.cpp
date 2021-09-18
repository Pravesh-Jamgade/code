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

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	map<string, bool> mp;
	mp["tmp0"]=false;
	mp["tmp1"]=true;
	mp["tmp2"]=false;

	for(auto e: mp){
		cout<<e.first<<" "<<e.second<<endl;
	}

	vector<vector<char>> vec(10, vector<char>(10, 'x'));

	for(auto row: vec){
		for(auto e: row){
			cout<<e<<" ";
		}cout<<'\n';
	}
	return 0;
}