#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define array ar
#define vpii vector<pair<int, int>>
typedef long long ll;


const int mxN = 1e+5;
const int mod = 1e+9;
vpii g[mxN];

/* these only counts sum total of all edges with cost(edge)=1*/
int dfs(int s, vi& sst, vector<bool>& vis){
	vis[s]=true;
	sst[s]=1;
	for(auto c: g[s]){
		if(vis[c.se]) continue;
		sst[s] += dfs(c.se, sst, vis);
		
	}
	return sst[s];
}

void contribution(int node, int v, int& ans, vector<bool>& vis,vi& sst){
	vis[node]=true;
	for(auto c: g[node]){
		if(vis[c.se]) continue;
		ans += sst[c.se] * (v-sst[c.se]);
		contribution(c.se, v, ans, vis, sst);
	}
}

void solve(int v){
	vi sst(v+1, 0);
	vector<bool> vis(v+1, false);
	dfs(1, sst, vis);
	fill(vis.begin(), vis.end(), false);
	int ans=0;
	contribution(1, v, ans, vis, sst);
	cout<<ans<<endl;
}

/*we want to calculate sum of cost of all paths possible*/

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n;
	cin>>n;

	for(int i=0; i< n-1; i++){
		int x,y,w;
		cin>>x>>y>>w;
		g[x].pb({w,y});
		g[y].pb({w,x});
	}

	/*1st*/
	solve(n);
	/*2nd*/
	
	return 0;
}
/*Question
Sum
Roman’s parents gave him an undirected connected weighted graph with n vertexes and n - 1 edges. Roman wants to know the sum of all the paths’ lengths in this graph. Let’s consider path’s length as sum of all the edges that lay on this path. Roman said that the path from u to v is the same as from v to u, so he doesn’t distinguish them.

Input
The first line contains the single integer number n (2 ≤ n ≤ 105) – the number of vertexes in graph. It is followed by n - 1 lines containing the description of the edges. Every line of description consists of three integer numbers: vertices connected by the edge (labeled from 1 to n) and edge’s weight.

Output
Print he sum of all the paths’ lengths in the given graph modulo 109.
*/

/*
3
1 2 1
1 3 3

and 

6
1 2 5
1 3 1
2 4 2
2 5 4
2 6 3
*/