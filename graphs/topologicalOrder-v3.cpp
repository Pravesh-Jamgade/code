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

	void solve(vector<int>& in);
};

void Graph2::solve(vector<int>& in){

	// get all indegree 
	// find and push zero indegree vertex to queue
	// until queue is empty follow:
		// remove queue top implies removing edge
		// hence reduce indegree of corresponding vertices
		// find if any vertes has indegree zero and push it into queue
		// print poped item from queue O(V+E)
	
	for(int i=0 ; i< v; i++){
		for(auto e: g[i]){
			in[e] += 1;
		}
	}

	queue<int> zero;
	for(int i=0; i< v; i++){
		if(in[i] == 0) zero.push(i);
	}

	cout<<"topological order: \n";
	while(!zero.empty()){
		int t = zero.front();
		zero.pop();

		for(auto e: g[t]){
			in[e]-=1;
			if(in[e] == 0){
				zero.push(e);
			}
		}
		cout<<t<<" ";
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

	vector<int> in(v, 0);
	g.solve(in);
	
}