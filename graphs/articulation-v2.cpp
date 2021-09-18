#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
vector<int>g[mxN];
vector<int> low, disc, parent;
vector<bool> AP;
vector<bool> vis;
int  timer = 0;

void dfs(int s){
	vis[s] = true;
	disc[s]=low[s]=timer++;

	int child = 0;
	for(int e: g[s]){
		if(!vis[e]){
			child= child + 1;
			parent[e] = s;
			dfs(e);
			low[s] = min(low[e], low[s]);
			if(parent[s] == -1 and child>1){
				AP[s] = true;
			}

			if(parent[s] != -1 and low[e]>= disc[s]){
				AP[s] = true;
			}
		}
		else if(parent[s]!=e){
			low[s] = min(low[s], disc[e]);
		}
	}	
}

int main(){

	freopen("input.txt", "r", stdin);
	int n,e;
	cin>>n>>e;

	for(int i=0; i< e; i++){
		int x,y; cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	low.resize(n, 0);
	disc.resize(n, 0);
	parent.resize(n, 0);
	AP.resize(n, false);
	for(int i=0; i< n; i++){
		parent[i]=i;
	}

	vis.resize(n, false);

	parent[1] = -1;
	dfs(1);

	cout<<"Articulation Point: ";
	for(int i=0; i< n; i++) {
		if(AP[i]){
			cout<<i<<" ";
		} 
	}
	return 0;
}