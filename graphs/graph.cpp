#include<bits/stdc++.h>
using namespace std;


class Graph1{
public:
	list<int>* g;
	int v;
	Graph1(int x){
		v = x;
		g = new list<int>[v];
	}
};

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

};

int main(){

	freopen("input.txt", "r", stdin);
	int v; cin>>v;
	int e; cin>>e;
	Graph2 g(v);

	for(int i=0; i<e; i++){
		int x,y; cin>>x>>y;
		g.addEdge(x,y);
	}

	g.test();
	return 0;

}