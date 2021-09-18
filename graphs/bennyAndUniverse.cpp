#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e9+1;
/*input https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/benny-and-the-universe/
3 3
5 6 7
5
10
8
*/

vector<int>g[mxN];

int main(){
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n,q;
	cin>>n>>q;

	vector<int> vn(n, 0);
	for(int i=0; i< n; i++){
		cin>>vn[i];
	}

	sort(vn.begin(), vn.end());

	set<int> all;
	for(int i=0; i< n; i++){
		int t = vn[i];
		g[t].push_back(t);
		all.insert(t);
		for(int j=i; j< n; j++){
			int sum = t + vn[j];
			g[t].push_back(sum);
			g[sum].push_back(t);
			all.insert(sum);
		}
	}

	int start = vn[0];

	for(int i=0; i< q; i++){
		int x; cin>>x;
		bool f = false;
		if(all.find(x) != all.end()) f = true;

		queue<int> q; q.push(start);
		vector<bool> vis(n*n, false);
		while(!q.empty()){
			int c = q.front(); q.pop();
			
			for(auto e: g[c]){
				if(vis[e])continue;
 				vis[e] = true;
				if(x%e == 0){
					f = true; break;
				}
			}
		}

		if(f) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}