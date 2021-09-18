#include <bits/stdc++.h>
using namespace std;


class Graph2{
public:
	int v;
	set<int, greater<int>>* g;
	vector<int> res;
	Graph2(int x){
		v = x;
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

	void solve();
	void solve2();
	void dfs(int s, vector<bool>& vis, stack<int>& st);
	void dfs2(int t, vector<bool>& vis);
};

void Graph2::dfs(int s, vector<bool>& vis, stack<int>& st){
	vis[s] = true;
	for(auto e: g[s]){
		if(vis[e]) continue;
		dfs(e, vis, st);
	}
	st.push(s);
}

void Graph2::dfs2(int t, vector<bool>& vis){
	vis[t] = true;
	for(auto e: g[t]){
		if(vis[e]) continue;
		cout<<e<<" ";
		dfs2(e, vis);
	}
	res.push_back(t);
}

void Graph2::solve(){
	stack<int> st;
	vector<bool> vis(v, false);
	for(int i=0; i< v; i++){
		if(vis[i]) continue;
		dfs(i, vis, st);
	}

	fill(vis.begin(), vis.end(), false);
	if(!st.empty()){
		int t = st.top();
		dfs2(t, vis);
	}
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

	g.test();

	g.solve();
	
}