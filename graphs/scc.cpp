#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
vector<int>g[mxN];
vector<int>gt[mxN];

vector<bool>vis;
stack<int> s;
vector<int> con;
int ti= 1;
int co = 0;

void dfs1(int i){
	vis[i]=1;
	for(auto e: g[i]){
		if(vis[e] )continue;
		dfs1(e);
	}
	s.push(i);
}

void dfs2(int i){
	vis[i]=true;
	con[i]=ti;
	for(auto e: gt[i]){
		if(!vis[e]){
			dfs2(e);
		}		
	}
}

int main(){

	freopen("input.txt", "r", stdin);

	int n,e;
	cin>>n>>e;

	for(int i=0; i< e; i++){
		int x,y; cin>>x>>y;
		g[x].push_back(y);
		gt[y].push_back(x);
	}
	vis.resize(n+1, false);


	for(int i=1; i<= n; i++){
		if(!vis[i])
			dfs1(i);
	}

	vis.assign(n+1, false);
	con.resize(n+1, 0);

	while(!s.empty()){
		int c = s.top(); s.pop();
		if(!vis[c]){
			dfs2(c);
			ti++;
			co++;
		}
	}

	cout<<"components: "<<co<<endl;
	for(int i=1; i<= n; i++){
		cout<<i<<" "<<con[i]<<endl;
	}
	return 0;
}