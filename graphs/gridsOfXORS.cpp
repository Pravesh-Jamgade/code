#include<bits/stdc++.h>
using namespace std;

#define fi first 
#define se second

const int mxN = 1e3;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;

int t,n,m,sx,sy,ex,ey;
bool vis[mxN][mxN] = {0};

bool isValid(int x, int y){
	if(x>=0 and x<n and y>=0 and y<m ){
		if(!vis[x][y]) return true;
	}
	return false;
}


int main(){

	freopen("input.txt", "r", stdin);
	cin>>t;
	while(t--){
		
		
		cin>>n>>m;
		int M[n][m];
		cin>>sx>>sy>>ex>>ey;
		sx--, sy, ex--, --ey;
		for(int i=0; i< n; i++){
			for(int j=0; j< m; j++){
				cin>>M[i][j];
				vis[i][j] = false;
			}
		}

		int dx[] = {-1,0,1,0};
		int dy[] = {0,-1,0,1};

		priority_queue<pii,  vector<pii>, greater<>> q;
		q.push({0, {sx,sy}});
		

		int cost = 0;
		while(!q.empty()){
			pii c = q.top(); q.pop();
			pi g = c.se;
			if(vis[g.fi][g.se]) continue;
			vis[g.fi][g.se] = true;

			// cout<<c.fi<<", ";
			cost = cost + c.fi;
			for(int i=0; i< 4; i++){
				int x,y; 
				x=g.fi+dx[i]; 
				y=g.se+dy[i];
				if(isValid(x,y) ){
					int tmp = (M[x][y] ^ M[g.fi][g.se]);
					q.push({tmp, {x,y}});
				}
			}
		}

		cout<<"cost: "<<cost<<endl;

	}
	return 0;
}