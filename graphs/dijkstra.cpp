#include<bits/stdc++.h>
using namespace std;

/* single source shothest path */

/*input
3 3
1 2 1
1 3 4
2 3 1
3
*/

#define fi first
#define se second

typedef pair<int,int> pi;
const int mxN = 1e3+7;

vector<int> d;
vector<bool> vis;
vector<pi> g[mxN];
vector<int> path;

void solve(){
	priority_queue<pi, vector<pi>, greater<>> q;
	q.push({0,1});

	while(!q.empty()){
		pi c = q.top(); q.pop();
		if(vis[c.se]) continue;
		vis[c.se] = true;

		for(auto e: g[c.se]){
			if(!vis[e.se]){
				if(d[e.se] > c.fi + e.fi){
					d[e.se] = c.fi + e.fi;
					q.push({d[e.se], e.se});
					path[e.se] = c.se;
				}
			}
		}

	}
}

int main(){
		freopen("input.txt", "r", stdin);
	int n,e;
	cin>>n>>e;
	for(int i=0; i< e; i++){
		int x,y,w; cin>>x>>y>>w;
		g[x].push_back({w,y});
		g[y].push_back({w,x});
	}

	vis.resize(n+1, false);
	d.resize(n+1, INT_MAX);
	path.resize(n+1, 0);

	d[1] = 0;

	solve();

	
	int y; cin>>y;
	
	cout<<"path from "<<1<<" to "<<y<<endl;

	string p = "";
	int s = 1;
	while(s!=y){
		p = p + ">-" + to_string(y);
		y = path[y];
	}

	p += ">-" + to_string(1);

	reverse(p.begin(), p.end());
	cout<<p<<endl;


	return 0;
}