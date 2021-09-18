#include <bits/stdc++.h>
using namespace std;


class Graph2{
public:
	int v;
	set<int, greater<int>>* g;
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
	void dfs1(int s, vector<bool>& vis, stack<int>& st);
	void dfs2(int s, vector<bool>& vis);
};

void Graph2::dfs2(int s, vector<bool>& vis){
	vis[s] = true;
	for(auto e: g[s]){
		if(vis[e]) continue;
		dfs2(e,vis);
	}
}

void Graph2::dfs1(int s, vector<bool>& vis, stack<int>& st){
	vis[s] = true;
	st.push(s);
	for(auto e: g[s]){
		if(vis[e]) continue;
		dfs1(e, vis, st);
	}
}

void Graph2::solve(){
	stack<int> st;
	vector<bool> vis(v, false);
	for(int i=0; i< v; i++){
		if(vis[i]) continue;
		dfs1(i,vis,st);
	}

	int k = 0;

	fill(vis.begin(), vis.end(), false);
	while(!st.empty()){
		int tt = st.top();
		st.pop();
		if(vis[tt]) continue;
		dfs2(tt, vis); 
		cout<<tt<<endl;
		k++;
		cout<<endl;
	}


	cout<<"components: "<<k<<endl;
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
	return 0;
}