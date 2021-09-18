#include<bits/stdc++.h>
using namespace std;

#define MAX 10000
vector<int>g[MAX];
vector<int> score;
vector<bool> vis;
int n,m;

void solve(int s, int d){
	score.resize(n+1, INT_MAX);
	vis.resize(n+1, false);

	score[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		vis[cur] = true;
		for(auto e: g[cur]){
			if( d == e) break;
			if(vis[e]) continue;
			q.push(e);
			int t = score[cur] + 1;
			score[e] = min(t, score[e]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0; i< m; i++){
			int x,y; cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		solve(1, n);
		cout<<score[n]<<endl;
		
		score.clear();
		vis.clear();
	}


	return 0;
}