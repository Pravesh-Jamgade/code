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


const int mxN = 1e5  + 1;
const int mod = 1e9;
vpii g[mxN];

bool dfs(int s, vector<bool>& vis, int& pc){
	if(vis[s]) return true;
	vis[s]=true;

	int tmp = pc;
	for(pii d: g[s]){
		if(vis[d.se]) continue;
		pc+= d.fi%mod;
		dfs(d.se, vis, pc);
		pc+=tmp%mod;
	}

	return true;
}

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

	int total = 0;
	for(int i=1; i<= n; i++){
		vector<bool> vis(n+1, false);
		int pc=0;
		dfs(i, vis, pc);
		total += pc%mod;
	}
	total=(total%mod)/2;
	cout<<total<<endl;
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