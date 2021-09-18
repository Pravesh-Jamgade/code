#include<bits/stdc++.h>
using namespace std;

/*input
12
1 2
2 3
3 4
1 5
1 6
3 7
4 8
1 6
2 7
3 8
2 5
3 6
4 7
5 9
5 10
5 6
6 9
6 10
6 11
6 7
7 10
7 11
7 12
7 8
8 12
9 10
10 11
11 12
1 12
*/
/*length of graph is number of edges*/

const int mxN = 1e3;
vector<int> g[mxN];
vector<bool> vis;

int c = 0;
void dfs(int s){
	vis[s] = true;
	for(auto e: g[s]){
		c++;
		if(vis[e]) continue;
		
		dfs(e);
	}
}

int main(){
	freopen("input.txt", "r", stdin);

	int n;
	cin>>n;

	int x,y;
	while(cin>>x>>y){
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vis.resize(n+1, false);
	dfs(1);
	cout<<(c/2)<<endl;
	return 0;
}