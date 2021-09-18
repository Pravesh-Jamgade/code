#include<bits/stdc++.h>
using namespace std;

class Graph2{
public:
	static int c;
	int v;
	set<int, greater<int>>*g;

	Graph2(int v){
		this->v = v;
		g = new set<int, greater<int>>[v];
	}

	void addEdge(int u, int v){
		g[u].insert(v);
	}


	void test(){
		for(int i=0; i< v; i++){
			cout<<i<<" : ";
			for(auto e: g[i]){
				cout<<e<<" ";
			}
			cout<<endl;
		}
	}

	void solve(int u, int v);
	void dfs2(int u, int v, vector<bool>& vis, int &k);
	void dfs1(int u, int v, vector<bool>& vis, int &k);
};

int Graph2::c = 0;

void Graph2::dfs2(int s, int d, vector<bool>& vis, int& k){

	stack<int> st;
	st.push(s);
	while(!st.empty()){
		int t = st.top();

		st.pop();
		for(auto e: g[t]){
			if(e == d) {
				k++;
			}
			if(vis[e]) continue;
			st.push(e);
 		}
	}
}

void Graph2::dfs1(int u, int v, vector<bool>& vis, int& k){
	vis[u] = true;
	for(auto e: g[u]){
		if(e == v)k++;
		if(vis[e]) continue;
		dfs1(e,v,vis,k);
	}
}

void Graph2::solve(int u, int v){
	int k = 0;

	vector<bool> vis(v, false);
	dfs2(u,v,vis,k); cout<<k<<'\n';
	fill(vis.begin(), vis.end(), false);
	k=0;
	dfs1(u,v,vis,k);
	cout<<k;
}

int main(){
	freopen("input.txt", "r", stdin);
	int v; cin>>v;
	int e; cin>>e;

	Graph2 g(v);
	for(int i=0; i< e; i++){
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}

	int x,y;
	cin>>x>>y;
	// g.test();
	g.solve(x,y);
	return 0;
}