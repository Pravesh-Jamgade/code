#include<bits/stdc++.h>
using namespace std;

const int mxN=1e3;
vector<int> g[mxN];
vector<bool> vis;

int edge[mxN][mxN];

void dfs(int s, int d){
	vis[s] = true;
	for(auto e: g[s]){
		if(vis[e]) continue;
		
		if(e == d) return;
		dfs(e, d);
		edge[s][e]++;
	}
}

int main(){

	freopen("input.txt", "r", stdin);
	int n,e;
	cin>>n>>e;

	int s,d; cin>>s>>d;

	for(int i=0; i< n; i++){
		for(int j=0; j< n; j++){
			edge[i][j] = 0;
		}
	}

	for(int i=0; i< e; i++){
		int x,y; 
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vis.resize(n, false);

	dfs(1, d);

	int x = 1;
	int y = 1;
	cout<<"  ";
	for(int i=0; i< n; i++)
		cout<<(i+1)<<" ";

	cout<<endl;
	for(int i=0; i< n; i++){
		cout<<x<<" "; x++;
		for(int j=0; j< n; j++){
			cout<<edge[i][j]<<" ";
		}
		cout<<'\n';
	}
		

	return 0;
}