#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3;
set<int> g[mxN];
vector<bool> vis;

void dfs(int s){
	vis[s] = true;
	for(auto e: g[s]){
		if(!vis[e]){
			dfs(e);
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);

	int n,e; cin>>n>>e;
	for(int i=0; i< e; i++){
		int x,y; cin>>x>>y;
		g[x].insert(y);
		g[y].insert(x);
	}

	vis.resize(n,false);

	int count = 0;

	/* count connected components */
	int initial_val = 0;
	for(int i=0; i< n; i++){
		if(!vis[i]){
			dfs(i);
			initial_val += 1;
		}
	}

	
	/* 
		consider each node, disable it, 
		again count connected components, 
		if components increased then its 
		a Articulation point
	*/
	for(int i=0; i< n; i++){

		vector<int> copy(n);
		int k=0;

		for(auto e: g[i]){
			copy[k++] = e;
		}

		for(auto e: copy){
			g[e].erase(i);
			g[i].erase(e);
		}

		/* counting components */
		
		fill(vis.begin(), vis.end(), false);

		int nval = 0;
		for(int j=0; j< n; j++){
			cout<<vis[j];
			if(vis[j]==false and j!=i){
				nval = nval + 1;
				dfs(j);
			}
		}

		if(nval > initial_val){
			count += 1;
		}

		for(auto e: copy){
			g[i].insert(e);
			g[e].insert(i);
		}

	}

	cout<<"total articulation points are: "<<count<<endl;



	return 0;
}