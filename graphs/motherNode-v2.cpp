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
	void dfs(int s, vector<bool>&vis, stack<int>&st);

};

void Graph2::dfs(int s, vector<bool>&vis, stack<int>&st)
{
	vis[s] = true;
	for(auto e: g[s]){
		if(vis[e]) continue;
		dfs(e, vis, st);
		st.push(e);
	}
	st.push(s);
}

void Graph2::solve(){

	vector<bool> vis(v, false);

	stack<int> st;
	for(int i=0; i< v; i++){
		bool flag = any_of(vis.begin(), vis.end(), [](bool a){
			return false == a;
		});
		if(!flag) break;
		if(vis[i]) continue;
		dfs(i, vis, st);
	}

	cout<<"mother: "<<st.top()<<endl;
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

	g.solve();
	return 0;
}