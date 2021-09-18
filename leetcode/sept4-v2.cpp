#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define ar array
typedef long long ll;
/*
6
5
0 1
0 2
2 3
2 4
2 5
*/
vvi edge;
vvi mat;

int dfs(int p, int n, vector<bool>& vis){
	vis[p] = true;
	for(auto e: edge[p]){
		for(int i: edge[e]){
			int tmp = 0;
			if(i == n){
				tmp = mat[e][i]>0?mat[e][i]:-1;
				if(mat[e][i] <0) mat[e][i]=dfs(e,i,vis);
				if(tmp > 0) {
					tmp = tmp + mat[p][e];
					return tmp;
				}

			}
		}
	}
	return -1;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	int n, e; cin>>n>>e;
	edge.resize(n);
	mat.resize(n, vi(n, -1));
	
	vvi mat(n, vi(n, -1));
	for(int i=0; i< e; i++){
		int x,y;
		cin>>x>>y;
		edge[x].pb(y);
		edge[y].pb(x);
		mat[x][y]=mat[y][x]=1;
	}

	int i=0;
	for(auto row: edge){
		cout<<i<<" :"; i++;
		for(auto e: row){
			cout<<e<<" ";
		}
		cout<<endl;
	}
cout<<endl;
		for(int i=0; i< n; i++){
			for(int j=0; j< n; j++){
				cout<<mat[i][j]<<" ";	
			}
			cout<<endl;
		}
		cout<<endl;
	int nt= n;
	while(nt--){
		for(int i=0; i< n; i++){
			for(int j=0; j< n; j++){
				if(mat[i][j] == -1){
					vector<bool> vis(n, false);
					if(i==j) continue;
					mat[i][j]=dfs(i, j, vis);
				}
			}
		}
	}

	vi dist(n,0);
	for(int i=0; i< n; i++){
			for(int j=0; j< n; j++){
				if(mat[i][j] > 0)
					dist[i] += mat[i][j];	
			}

		}

		for(auto e: dist){
			cout<<e<<" ";
		}

cout<<endl;
		for(int i=0; i< n; i++){
			for(int j=0; j< n; j++){
				cout<<mat[i][j]<<" ";	
			}
			cout<<endl;
		}

	return 0;
}