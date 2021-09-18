#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<int, pi> pii;

const int mxN = 1e+3;

int n,m;
int dx[] = {-1,-1,-1, 0,0, 1,1,1};
int dy[] = {-1,0,1, -1,1, -1,0,1};
string dr = "aUbLRdDc";

char M[mxN][mxN] = {'.'};

bool vis[mxN][mxN] = {0};

bool isValid(int x, int y){
	if(x>=0 and x<n and y>=0 and y<m){
		if(!vis[x][y] and (M[x][y]=='.' or M[x][y]=='b' or M[x][y]=='a' )) return true;
	}
	return false;
}

string route = "";
bool dfs(pi p, pi d){
	
	cout<<"\n"<<p.fi<<","<<p.se<<" && "<<d.fi<<","<<d.se <<endl;
	if(M[p.fi][p.se] == M[d.fi][d.se]) return true;
	vis[p.fi][p.se] = true;

	for(int i=0; i< 8; i++){
		int tx,ty;
		tx = p.fi + dx[i];
		ty = p.se + dy[i];
		if(!isValid(tx,ty)) continue;
		
		char prev = M[p.fi][p.se];
		M[p.fi][p.se] = dr[i];
		if(dfs({tx,ty}, d)) {
			route += dr[i];
			return true;
		}
	}
	return false;
}

int main(){

	freopen("input.txt", "r", stdin);

	cin>>n>>m;

	
	vector<string> g;
	for(int i=0; i< n; i++){
		string tmp;
		cin>>tmp; g.push_back(tmp);
	}

	int r,c,dr,dc;
	cin>>r>>c>>dr>>dc;
	r--, c--, dr--, dc--;

	for(int i=0; i< n; i++){
		for(int j=0; j< m; j++){
			M[i][j] = g[i][j];
		}
	}

	M[r][c] = 'a'; 
	M[dr][dc] = 'b'; 

	cout<<"input graph: \n";
	for(int i=0; i<n; i++){
		cout<<g[i]<<endl;
	}

	cout<<"dir-copied graph: \n";
	for(int i=0; i< n; i++){
		for(int j=0; j< m; j++){
			cout<<M[i][j]<<" ";
		}cout<<endl;
	}
	
	cout<<dfs({r,c}, {dr,dc})<<endl;

	reverse(route.begin(), route.end());
	cout<<route<<endl;
	cout<<"dir-update graph: \n";
	for(int i=0; i< n; i++){
		for(int j=0; j< m; j++){
			cout<<M[i][j]<<" ";
		}cout<<endl;
	}
	
	return 0;
}