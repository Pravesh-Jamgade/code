#include <bits/stdc++.h>
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
	void bfs(int s);
	void solveBFS1(int s, vector<bool>& vis);
	void solveBFS2(int s, vector<bool>& vis);
};

void Graph::addEdge(int u, int v){
	g[u].push_back(v);
}

void Graph::solveBFS1(int s, vector<bool>& vis){
	
	if(vis[s]) return;
	cout<<s<<" ";
	vis[s] = true;

	for(auto e: g[s]){
		adj.push(e);
	}

	while(!adj.empty()){
		int e = adj.front();
		adj.pop();
		solveBFS1(e, vis);
	}
}

void Graph::solveBFS2(int s, vector<bool>& vis){
	vis[s] = true;
	queue<int> q;
	q.push(s);

	while(!q.empty()){
		s = q.front();
		cout<<s<<" ";
		q.pop();

		for(auto e: g[s]){
			if(vis[e]) continue;
			vis[e] = true;
			q.push(e);
		}
	}
}

void Graph::bfs(int s){
	vector<bool> vis(v, false);
	solveBFS1(s, vis);
	fill(vis.begin(), vis.end() +1, false);
	cout<<"\n";
	solveBFS2(s, vis);
}


int main(){
	freopen("input.txt", "r", stdin);
	int v;
	cin>>v; cout<<v<<endl;
	Graph g(v);

	for(int i=0; i< v; i++){
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}
	
	g.bfs(2);


}