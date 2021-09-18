#include<bits/stdc++.h>
using namespace std;
#define MAX 10
/*MEDIUM*/

vector<int> g[MAX];
int r,c;

pair<int,int> max(int n){
	int d = n;
	int m = -1;
	for(int i=2; i*i<= n; i++){
		if(d%i==0){
			if(m < i) m = i;
			all.push_back(i);
		}
	}

	return {m, all.size()};
}


int d[] = {-1,0, 0,-1, 1,0, 0,1};

void bfs(int i, int j, int pm, int ps){
	if((i<0 or j<0) || (i>r or j>c)) return;

	for(int x=0; x< 8; x+=2){
		bfs(i+d[x], j+d[x+1], );
	}
}

int main(){

	freopen("input.txt", "r", stdin);
	cin>>r>>c;

	for(int i=0; i< r; i++){
		vector<int> vec;
		for(int j=0; j< c; j++){
			int t; cin>>t;
			vec.push_back(t);
		}
		g[i] = vec;
	}

	// for(int i=0; i< r; i++){
	// 	for(auto e: g[i]){
	// 		cout<<e<<" ";  
	// 	}cout<<endl;
	// }

	for(int i=0; i< r; i++){
		for(int j=0; j< c; j++){
			int mx = max(g[i][j]).first;
			int size = max(g[i][j]).second;
			bfs(i, j, mx, size);
		}
	}


	return 0;
}