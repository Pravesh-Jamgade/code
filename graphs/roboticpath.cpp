#include<bits/stdc++.h>
using namespace std;

/*input
5 5
.....
..#..
.....
#.##.
.#...
5
1 3 3 3
2 2 2 4
4 2 1 3
1 1 5 1
1 1 5 5
*/
#define fi first
#define se second
typedef pair<int,int> pi;

const int mxN = 1e3+1;
int dx[] = {-1,0,1,0}; /* ULDR*/
int dy[] = {0,-1,0,1};
string RT = "ULDR";

vector<vector<bool>> vis;
vector<string> m;
int r,c;

bool isValid(int x, int y){
	if(x>=0 and x<r and y>=0 and y<c) {
		if(!vis[x][y] and m[x][y] != '#'){
			return true;	
		}
	}
	return false;
}

void init(){
	vis.resize(r);
	for (int i = 0; i < r; ++i){
		vis[i].resize(c, 0);
	}
}

int main(){

	freopen("input.txt", "r", stdin);
	cin>>r>>c;

	for(int i=0; i< r; i++){
		string s; cin>>s;
		m.push_back(s);
	}

		 
	vector<vector<int>> d(r, vector<int> (c, -1));
	int q; cin>>q;
	while(q--){
		init();
		int sx,sy,fx,fy;
		cin>>sx>>sy>>fx>>fy;
		sx--; sy--; fx--; fy--;
		cout<<"("<<sx<<","<<sy<<")"<<" to "<<"("<<fx<<","<<fy<<")"<<endl;
		string path = "";
		queue<pi> qu;
		qu.push({fx,fy});
		vis[fx][fy] = true;
		d[fx][fy] = 0;
		while(!qu.empty()){
			pi c = qu.front(); qu.pop();
			int x,y;  x=c.fi; y=c.se;

			for(int i=0; i< 4; i++){
				int tx,ty;
				tx=x+dx[i]; ty=y+dy[i];
				if(isValid(tx,ty)){
					vis[tx][ty] = true;
					qu.push({tx,ty});
					d[tx][ty] = d[x][y] + 1;
				}
			}
		}

		init();
		bool f = false;
		while(1){
			
			cout<<"MAIN: ("<<sx<<","<<sy<<")"<<" to "<<"("<<fx<<","<<fy<<")"<<endl;
			if(sx == fx and sy == fy) break;
			for(int i=0; i< 4; i++){
				int tx,ty; tx=sx+dx[i]; ty=sy+dy[i];
				cout<<"("<<sx<<","<<sy<<")"<<" to "<<"("<<tx<<","<<ty<<")"<<endl;
				if(isValid(tx, ty)){
					if(d[sx][sy] == d[tx][ty]+1){

						sx=tx; sy=ty;
						path = path + RT[i];
						break;
					}
				}
			}

			if(f){
				break;
			}
			f = true;
		}

		for(auto v: vis){
			for(auto e: v){
				cout<<e<<" ";
			}cout<<endl;
		}

		cout<<path<<endl;
		break;
	}
	
	for(int i=0; i< r; i++){
		for(int j=0; j< c; j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}	

	for(int i=0; i< r; i++){
		for(int j=0; j< c; j++){
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}