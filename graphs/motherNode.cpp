#include<bits/stdc++.h>
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
	void dfs(int s, vector<bool>&vis);

};

void Graph2::dfs(int s, vector<bool>& vis){
	stack<int> st;
	st.push(s);
	while(!st.empty()){
		int c = st.top();
		st.pop();
		vis[s] = true;
		for(auto e: g[c]){
			if(vis[e]) continue;
			vis[e] = true;
			st.push(e);
		}
	}
}

void Graph2::solve(){
	vector<bool> vis(v, false);
	for(int i=0; i< v; i++){
		dfs(i, vis);
		bool flag = any_of(vis.begin(), vis.end(), 
			[](bool a){ 
				return a==false;
			}
		);

		if(!flag){
			cout<<"mother :"<<i<<endl;
			break;
		}

		fill(vis.begin(), vis.end(), false);
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

	g.solve();

	return 0;
}