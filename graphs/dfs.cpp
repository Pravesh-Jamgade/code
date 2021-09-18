#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
	list<int> *g;
	int v;
	queue<int> adj;

	Graph(int x){
		v = x;
		g = new list<int>[v];
	}
	void addEdge(int u, int v);
	void dfs(int s);
	void solveDFS(int s, vector<bool>& vis);
};

void Graph::addEdge(int u, int v){
	g[u].push_back(v);
}

void Graph::solveDFS(int s, vector<bool>& vis){
	vis[s] = true;
	cout<<s<<" ";
	for(auto e: g[s]){
		if(vis[e]) continue;
		solveDFS(e, vis);
	}
}

void Graph::dfs(int s){
	vector<bool> vis(v, false);
	solveDFS(s, vis);
}

int main(){
	freopen("input.txt", "r", stdin);
	
	int v;
	cin>>v;
	Graph g(v);
	for(int i=0; i< v; i++){
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}

	g.dfs(2);

	return 0;
}