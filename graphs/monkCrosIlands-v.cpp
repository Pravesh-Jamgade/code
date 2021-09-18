#include<bits/stdc++.h>
using namespace std;

#define MAX 10000
vector<int>g[MAX];

int n,m;

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
		
		int numberOfEdges = 0;
		bool flag =false;
		queue<int>q;
		q.push(1);

		vis.resize(n, false);

		while(true){
			int nodeCount = q.size();
			if(nodeCount == 0)
				break;

			while(nodeCount--){
				int c = q.front(); q.pop();
				if(c == n){
					flag = true;
					break;
				}

				for(auto e: g[c]){
					if(!vis[e]){
						q.push(e);
						vis[e] = true;
					}
				}
			}

			if(flag) break;
			numberOfEdges++;
		}
		vis.clear();

		cout<<numberOfEdges<<endl;
	}


	return 0;
}