#include<bits/stdc++.h>
using namespace std;

struct edge{ int x,y,cost;};
vector<edge> e;

const int INF = 1e+9;

int main(){

	freopen("input.txt", "r", stdin);
	int n,m,v,t;

	cin>>n>>m>>v;

	for(int i=0; i< m; i++){
		int x,y,w; cin>>x>>y>>w;
		edge ed;
		ed.x = x; ed.y = y; ed.cost = w;
		e.push_back(ed);
	}

	vector<int> d(n, INF);
	d[v] = 0;
	vector<int> p(n, -1);

	for(;;){
		bool any = false;
		for(int j=0; j< m; j++){
			if( d[e[j].x] < INF){
				if(d[e[j].y] > d[e[j].x]+e[j].cost){
					d[e[j].y] = d[e[j].x] + e[j].cost;
					p[e[j].y] = e[j].x;
					any = true;
				}
			}
		}
		if(!any) break;
	}

	cin>>t; // path from v to t;
	if(d[t] == INF) cout<<"No path from "<<v<<" tp "<<t<<endl;
	else{
		vector<int> path;
		for(int cur= t; cur!=-1; cur=p[cur]){
			path.push_back(cur);
		}

		reverse(path.begin(), path.end());
		
		cout<<"path between "<<v<<" and "<<t<<endl;
		for(auto e: path){
			cout<<e<<" ";
		}
	}



	return 0;
}