#include<bits/stdc++.h>
using namespace std;


/*input
12
1 2
2 3
3 4
1 5
1 6
3 7
4 8
1 6
2 7
3 8
2 5
3 6
4 7
5 9
5 10
5 6
6 9
6 10
6 11
6 7
7 10
7 11
7 12
7 8
8 12
9 10
10 11
11 12
*/

const int mxN = 1e3;
struct Edge{ int x,y;};
vector<int>g[mxN];
vector<bool> vis;
vector<int> root;
vector<pair<int, Edge>> all;
vector<Edge> col;
string path="";

int getRoot(int x){
	while(x!= root[x]){
		x = root[x];
	}
	return x;
}

void uni(int x, int y){
	int tx = getRoot(x);
	int ty = getRoot(y);
	root[tx] = root[ty]; 
}

void findMst(int s){
	for(int i=0; i< all.size(); i++){
		Edge e = all[i].second;
		while(getRoot(e.x) != getRoot(e.y)){
			col.push_back(e);
			uni(e.x, e.y);
		}
	}
}

bool dfs(int s, int d, int& cost){
	vis[s] = true;
	for(auto e: g[s]){
		if(!vis[e]){
			cost = cost + 1;
			if(d == e) {

				return true;
			}
			if(dfs(e,d,cost)) {
				path += to_string(e) + ">-";
				return true;
			}
			cost = cost - 1;
		}
	}

}	

int main(){
	freopen("input.txt", "r", stdin);

	int n,e; cin>>n>>e;
	int x,y;
	while(e--){
		cin>>x>>y;
		all.push_back( 
			{ 1, Edge{x,y} }
		);
	}

	root.resize(n+1, 0);
	
	for(int i=0; i<=n; i++){
		root[i] = i;
	}

	vis.resize(n+1, false);
	findMst(1);

	for(int i=0; i< col.size(); i++){
		g[col[i].x].push_back(col[i].y);
		g[col[i].y].push_back(col[i].x);
	}

	int tx,ty,cost; cost = 0;
	cin>>tx>>ty;
	dfs(tx,ty,cost);
	cout<<"minimum cost from s:"<<tx<<" to:"<<ty<<" is: "<<cost<<endl;

	cout<<"mst edges: \n";
	for(auto e: col){
		cout<<e.x<<"-"<<e.y<<endl;
	}
	reverse(path.begin(), path.end());
	path= to_string(tx) + path + "->" + to_string(ty);
	cout<<"path: "<<path<<endl;

	return 0;
}