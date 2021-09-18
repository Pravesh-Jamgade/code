#include<bits/stdc++.h>
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
	void cycle(int s, int p);
};

bool Graph2::cycle(int s, int p){
	
}

void Graph2::solve(){
	vector<bool> vis(v, false);
	cycle(1,-1);
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