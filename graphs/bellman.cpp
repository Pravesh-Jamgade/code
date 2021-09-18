#include<bits/stdc++.h>
using namespace std;


/*Bellman Ford: Single Source Shortest Path Algorithm*/

#define MAX 100

struct edge{ int x,y,cost;};
int n,m,v;
vector<edge> e;
const int INF = 1e+9;

int main(){

	freopen("input.txt", "r", stdin);
	cin>>n>>m>>v;

	for(int i=0; i< m; i++){
		int x,y,w;
		cin>>x>>y>>w;
		edge t;
		t.x =x;
		t.y =y;
		t.cost =w;
		e.push_back(t);
	}

	for(int i=0; i< m; i++){
		cout<<e[i].x<<"->"<<e[i].y<<" "<<e[i].cost<<endl;
	}

	vector<int> d(n, INF);
	d[v] = 0;

	for(int i=0; i< n-1; i++){

		for(int j=0; j< m; j++){
			if(d[e[j].x] < INF){
				d[e[j].y] = min(d[e[j].y], d[e[j].x] + e[j].cost);
			} 
		}

	}

	cout<<"vertex"<<"   cost"<<endl;
	for(int i=0; i< n; i++){
		cout<<i<<" "<<d[i]<<endl;
	}


	return 0;
}