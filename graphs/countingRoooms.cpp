#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
#define  fi first
#define  se second
typedef pair<int,int> pi;
int h,w;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int vis[MAX][MAX] = {0};
vector<string>vec;

bool isValid(int x, int y){
	if(x<0 || x>w || y<0 || y>h) return false;
	if(vis[x][y]) return false;
	if(vec[x][y] == '#') return false;
	return true;
}

bool solve(int x, int y){
	if(vec[x][y] == '#') {
		vis[x][y] = false;
		return false;
	}

	queue<pi>q;
	q.push({x,y});

	while(!q.empty()){
		pi c = q.front(); q.pop();
		int x,y; x=c.fi; y=c.se;
		vec[x][y] = '#';
		vis[x][y] = true;

		for(int i=0; i< 8; i++){
			int tx,ty; tx = x + dx[i]; ty = y + dy[i];
			if(isValid(tx,ty)){
				q.push({tx,ty});
			}
		}
	}
	return true;
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

	int count1 = 0;
	for(int i=0; i< h; i++){
		for(int j=0; j< w; j++){
			if(vis[i][j]) continue;
			if(solve(i,j)) count1++;
		}
	}
	
	

	cout<<count1<<endl;
	return 0;
}