#include<bits/stdc++.h>
using namespace std;

class Graph2{
public:
	int v;
	set<int, greater<int>>* g;
	vector<bool> visited;
	vector<int> ans;
	Graph2(int x){
		v = x;
		g = new set<int, greater<int>>[v];
		visited.assign(v, false);
		ans.assign(v, -1);
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
	void dfs(int s);
	void topological_sort();
};

void Graph2::dfs(int s) {
    visited[s] = true;
    if(g[s].empty()) return;
    for(auto e: g[s]){
    	if(visited[e]) continue;
    	dfs(e);
    }
    ans.push_back(s);
}


void Graph2::topological_sort() {
	fill(visited.begin(), visited.end(), false);
    ans.clear();
    for (int i = 0; i < v; ++i) {
        if (!visited[i]){
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto e: ans) cout<<e<<" ";
}

void Graph2::solve(){
	topological_sort();
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