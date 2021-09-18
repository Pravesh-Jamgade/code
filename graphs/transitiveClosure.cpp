#include<bits/stdc++.h>

using namespace std;

class TransitiveClosure{
public:
	bool **tc;

	TransitiveClosure(int v){
		tc = new bool*[v];
		for(int i=0; i< v; i++){
			tc[i] = new bool[v];
			memset(tc[i], false, v*sizeof(bool));
		}
	}

	void set(int u, int v, bool flag){
		tc[u][v] = flag;
	}
};

class Graph2{
public:
	int v;
	set<int, greater<int>>* g;
	TransitiveClosure *T;

	Graph2(int x, TransitiveClosure *X){
		v = x;
		g = new set<int, greater<int>>[v];
		T = X;
	}

	void addEdge(int u, int v){
		g[u].insert(v);
		// g[v].insert(u);
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
	void DFSUtil(int s, vector<bool>& vis);

};

void Graph2::DFSUtil(int s, vector<bool>&vis){
	stack<int> st;
	st.push(s);
	while(!st.empty()){
		int c = st.top();
		vis[c] = true;
		T->tc[s][c] = true;
		st.pop();
		for(auto e: g[c]){
			if(vis[e]) continue;
			st.push(e);
		}
	}	
}

void Graph2::solve(){
	vector<bool> vis(v, false);
	for(int i=0; i< v; i++){
		fill(vis.begin(), vis.end(), false);
		DFSUtil(i, vis);
	}

	for(int i=0; i< v; i++){
		for(int j=0; j< v; j++){
			cout<<T->tc[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	int v; cin>>v;
	int e; cin>>e;
	Graph2 g(v, new TransitiveClosure(v));

	for(int i=0; i<e; i++){
		int x,y; cin>>x>>y;
		g.addEdge(x,y);
	}

	g.test();
	cout<<endl;
	g.solve();

	return 0;
}