#include<bits/stdc++.h>
using namespace std;

struct edge{
	int x,y,cost;
};


vector<edge> e;
int n,m,v;
const int INF = 1e+9;

int main(){

	freopen("input.txt", "r", stdin);
	cin>>n>>m>>v;

	for(int i=0; i< m; i++){
		int x,y,w; cin>>x>>y>>w;
		edge ed;
		ed.x = x; ed.y = y; ed.cost = w;
		e.push_back(ed);
	}

	vector<int> d(n, INF);
	d[v] = 0;

	for(;;){
		bool any = false;
		for(int j=0; j< m; j++){
			if(d[ e[j].x ] < INF){
				if(d[ e[j].y ] > d[ e[j].x ] + e[j].cost){
					d[e[j].y]  = d[e[j].x] + e[j].cost;
					any = true;
				}
			}
		}
		if(!any) break;
	}

	for(int i=0; i< n; i++){
		cout<<i<<" "<<d[i]<<endl;
	}

	return 0;
}