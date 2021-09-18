#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define ar array
typedef long long ll;
/*
6
5
0 1
0 2
2 3
2 4
2 5
*/


void dfs(int u, int d, int& sum, vector<bool>& vis, vvi edge){
	vis[u]=true;
	for(auto v: edge[u]){
		if(vis[v]) continue;
		dfs(v, d+1, sum, vis, edge);
	}
	sum += d;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int n, e; cin>>n>>e;

	vvi edge(n);

	for(int i=0; i< e; i++){
		int x,y;
		cin>>x>>y;
		edge[x].pb(y);
		edge[y].pb(x);
	}

	int i=0;
	for(auto row: edge){
		cout<<i<<" :"; i++;
		for(auto e: row){
			cout<<e<<" ";
		}
		cout<<endl;
	}


	vi dist(n, 0);
	for(int i=0; i< n; i++){
		vector<bool> vis(n, false);
		int sum = 0;
		int d= 0;
		dfs(i, d, sum, vis, edge);
		dist[i]=sum;
	}

	for(auto e: dist){
		cout<<e<<" ";
	}

	return 0;
}