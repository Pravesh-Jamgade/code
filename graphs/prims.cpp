#include<bits/stdc++.h>
using namespace std;


#define fi first
#define se second
typedef pair<int, int> pi;


const int mxN = 1e3+7;
vector<pi>g[mxN];
vector<bool> vis;

void prims(int s){

	priority_queue<pi, vector<pi>, greater<>> q;

	q.push({0, s});

	int cost = 0;

	while(!q.empty()){

		pi c = q.top();
		q.pop();

		int wt = c.fi;
		int v = c.se;

		if(vis[v]) continue;

		vis[v] = true;

		cost = cost + wt;
		
		for(auto e: g[v]){
			if(!vis[e.se]){
				q.push({e.fi, e.se});
			}
		}
	}

	cout<<"total cost: "<<cost<<endl;

}

int main(){

	freopen("input.txt", "r", stdin);

	int n,e;
	cin>>n>>e;

	vis.resize(n+1, false);

	for(int i=0; i< e; i++){
		int x,y,w;
		cin>>x>>y>>w; cout<<x<<y<<w<<endl;
		g[x].push_back({w,y});
		g[y].push_back({w,x});
	}

	prims(1);
	return 0;
}