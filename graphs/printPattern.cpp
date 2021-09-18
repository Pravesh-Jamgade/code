#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define fi first
#define se second

typedef pair<int,int> pi;

int a,b,c,d;

int m[MAX][MAX] = {0};
bool vis[MAX][MAX] = {0};
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool valid(int x, int y){
	if(x >=a or x<0 or y>=b or y<0) return false;
	if(vis[x][y]) return false;
	return true;
}

void bfs(int cx, int cy){
	m[cx][cy] = 0;
	queue<pi> q;
	q.push({cx,cy});
	while(!q.empty()){
		int x = q.front().fi;
		int y = q.front().se;
		q.pop();
		vis[x][y] = true;

		for(int i=0; i< 8; i++){
			// get neighbour
			int tx,ty;
			tx = ty = 0;
			tx = x + dx[i]; ty = y + dy[i];

			// check if already visited
			if(!valid(tx,ty)) continue;
			m[tx][ty] = m[x][y] + 1;

			// line up in queue
			q.push({tx, ty});

			// make it visited to not to change its value again. because we have to grow outward from given center
			vis[tx][ty] = true;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	cin>>a>>b>>c>>d;
	bfs(c,d);

	for(int i=0; i < a; i++){
		for(int j=0; j< b; j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<endl;
	for(int i=0; i < a; i++){
		for(int j=0; j< b; j++){
			cout<<vis[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}