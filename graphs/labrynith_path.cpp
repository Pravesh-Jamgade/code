#include<bits/stdc++.h>
using namespace std;

/*input
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/
#define MAX 10000
#define  fi first
#define  se second
typedef pair<int,int> pi;
int h,w;
int dx[] = { -1, 0, 0, 1}; /* 0  -> up, 1 -> left, 2 -> right, 3 -> bottom/down */
							/*ULRD*/
int dy[] = { 0, -1, 1, 0};
int vis[MAX][MAX] = {0};
int p[MAX][MAX];
vector<string>vec;
string rt = "ULRD";
string path = "";

char dir(int i, int j){
	if(i == -1 and j == 0) return 'U';
	if(i == 0 and j == 1) return 'R';
	if(i == 1 and j == 0) return 'D';
	if(i == 0 and j == -1) return 'L';
	return '#';
}

bool isValid(int x, int y){
	if(x>=0 || x<w || y>=0 || y<h) return true;
	return false;
}

bool solve(int x, int y){
	queue<pi> q;
	q.push({x,y});
	vis[x][y] = true;

	int fx,fy;
	bool f = false;
	p[x][y] = 1;
	while(!q.empty()){
		pi c = q.front(); q.pop();
		int x,y; x=c.fi; y=c.se;
		
		for(int i=0; i< 4; i++){
			int tx,ty;
			tx = x+dx[i]; ty = y+dy[i];
			
			if(isValid(tx,ty) and !vis[tx][ty] and vec[tx][ty]!='#'){
				q.push({tx,ty});
				p[tx][ty] = p[x][y] + 1;
				vis[tx][ty] = true;
			}
			
			if(vec[tx][ty] == 'B'){
				fx=tx; fy=ty;
				f = true; break;
			}
		}
	}


	if(f){

		if(p[fx][fy] == 0) return false;
		while(1){
			if(fx == x and fy == y) break;
			for(int i=0; i< 4; i++){
				int X = fx + dx[i];
				int Y = fy + dy[i];
				// cout<<"("<<X<<","<<Y<<")"<<endl;
				if(
					(isValid(X,Y) and p[fx][fy] == 1 + p[X][Y]) or (X == x and Y == y)
					){
					fx = X; fy = Y;
					cout<<"("<<X<<","<<Y<<")"<<endl;
					path = path + rt[i]; break;
				}
			}
		}
		return f;
	}

	return false;
}

int main(){
	freopen("input.txt", "r", stdin);
	cin>>h>>w;

	string s;
	
	for(int i=0; i< h; i++){
		cin>>s; vec.push_back(s);
	}

	for(int i=0; i< vec.size(); i++){
		cout<<vec[i]<<endl;
	}

	for(int i=0; i< h; i++){
		for(int j=0; j< w; j++){
			if(vec[i][j] == '#' or vec[i][j] == '.') continue;
			if(vec[i][j] == 'A'){
				if(solve(i,j)){
					reverse(path.begin(), path.end());
					cout<<path<<'\n';
					cout<<"YES\n";
				}else cout<<"NO\n";
			}
		}
	}

	for(int i=0; i< h; i++){
		for(int j=0; j< w; j++){
			cout<<vec[i][j]<<" ";
		}cout<<endl;
	}
	cout<<endl;
	for(int i=0; i< h; i++){
		for(int j=0; j< w; j++){
			cout<<p[i][j]<<" ";
		}cout<<endl;
	}
	
	return 0;
}