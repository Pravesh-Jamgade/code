#include<bits/stdc++.h>
using namespace std;

/*input
5 4
1 2
2 3
3 5
3 4
*/

const int mxN = 1e3;
int timer = 0;

vector<int> disc, low;
vector<bool> vis, AP;

typedef struct Edge{
	int x,y;
};

vector<Edge> all;
vector<int> g[mxN];

void dfs(int s, int p){
	vis[s] = true;
	low[s] = disc[s] = timer++;

	int child = 0;
	for(auto e: g[s]){
		if(!vis[e]){
			child++;
			dfs(e, s);

			low[s] = min(low[e], low[s]);

			if(p!=-1 and low[e]>=disc[s]){
				AP[s] = true;
			}

			if(p==-1 and child>1){
				AP[s] = true;
			}

			if(AP[s]){
				all.push_back(Edge{s,e});
			}
		}
		else if(p!=e){
			low[s] = min(low[s], disc[e]);
		}
	}
}

int main(){

	freopen("input.txt", "r", stdin);

	int n,e; cin>>n>>e;

	for(int i=0; i< e; i++){
		int x,y; cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	vis.resize(n+1, false);
	AP.resize(n+1, false);
	disc.resize(n+1, 0);
	low.resize(n+1, 0);

	dfs(1, -1);

	if(all.size()>0){
		cout<<"bridges are: \n";
		for(auto e: all){
			cout<<e.x<<"-"<<e.y<<endl;
		}

		cout<<"Articulation points are: \n";
		for(int i=0; i<= n; i++){
			if(AP[i]){
				cout<<i<<endl;
			}
		}
	}else cout<<"no bridges\n";

	return 0;
}