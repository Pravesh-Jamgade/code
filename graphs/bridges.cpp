#include<bits/stdc++.h>
using namespace std;

/*input
5 4
1 2
2 3
3 5
3 4
*/

/*
1. Iterate over edges
2. Remove edge from graph and compare original # of components with new graph where one is edge is less
3. if new components are more then edge was a bridge otherwise its not
4. Re-enable edge in graph and move to next edge
complexity = O(e*(v+e))
*/
typedef struct Edge{
	int x,y;
};

const int mxN = 1e3;
int g[mxN][mxN];
vector<Edge> allE;
vector<bool> vis;
vector<bool> bridges;
int n,e; 


void dfs(int u){
	vis[u] = true;
	for(int i=u; i<= n; i++){
		if(!g[u][i] or vis[i]) continue;
		dfs(i);
	}
}

int main(){

	freopen("input.txt", "r", stdin);

	cin>>n>>e;

	vis.resize(n+1, false);
	bridges.resize(n+1, false);

	for(int i=1; i<= n; i++){
		for(int j=1; j<= i; j++){
			g[i][j] = g[j][i] = 0;
		}
	}


	for(int i=1; i<= e; i++){
		int x,y; cin>>x>>y;
		g[x][y] = g[y][x] = 1;
		allE.push_back(Edge{x,y});
	}

	int p = 0;
	int q = 0;
	for(int i=1; i<= n; i++){
		if(!vis[i]){
			dfs(i);
			p++;
		}
	}

	for(int j=1; j<= e; j++){
		fill(vis.begin(), vis.end(), false);
		q = 0;

		Edge c = allE[j];
		g[c.x][c.y] = g[c.x][c.y] = 0;
		for(int i=1; i<= n; i++){
			if(!vis[i]){
				dfs(i);
				q++;
			}
		}
		cout<<c.x <<" -- "<<c.y<<"  components: "<<q<<endl;

		if(q>p) bridges[j]=true;

		g[c.x][c.y] = 1;
	}

	cout<<"bridges: "<<endl;
	for(int i=1; i<= e; i++){
		if(bridges[i]){
			cout<<allE[i].x<<"-"<<allE[i].y<<endl;
		}
	}

	return 0;
}