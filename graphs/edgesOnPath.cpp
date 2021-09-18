#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
vector<int> graph[mxN];
vector<int> U,V;

int dfs0()

int main(){

	freopen("input.txt", "r", stdin);
	int n,e;
	cin>>n>>e;

	U.resize(n); V.resize(n);
	
	int s,d; cin>>s>>d;
	s--; d--;
	
	for(int i=0; i< e; i++){
		int u,v; cin>>u>>v;
		u--, v--;
		U[i]=u; V[i]=v;
		graph[u].push_back(i);
		graph[v].push_back(i);
	}

	dfs0(0,-1);


	return 0;
}