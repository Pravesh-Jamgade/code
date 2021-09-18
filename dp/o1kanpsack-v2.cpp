#include<bits/stdc++.h>
using namespace std;
/*input
3 50
100,120,60
20,30,10

complex: O(N*W) 
*/
#define fi first
#define se second
typedef pair<int, int> pii;

const int mxN =1e3;
vector<int>p,w;
vector<pii> wp;
int dp[mxN][mxN];

int solve(int n, int W, int i){
	if(i<0)
		return 0;

	if(dp[i][W] != -1)
		return dp[i][W];

	/* current weight is grater than capacity, skip it */
	if(w[i] > W){
		dp[i][W] = solve(n, W, i-1);
		return dp[i][W];
	}
	else{
		/* current wweight is less than capacity, 
			two ways:
			+1, Include profit and reduce capacity by currrent wi
			+2, skip it and solve ahead
			once done return value
		*/
		dp[i][W] = max(
			p[i] + solve(n, W-w[i], i-1),
			solve(n, W, i-1)
		);
		return dp[i][W];
	}

}

int main(){
	freopen("input.txt", "r", stdin);

	int n, W;
	cin>>n>>W;

	for(int i=0; i< n; i++){
		for(int j=0; j<= W; j++){
			dp[i][j] = -1;
		}
	}

	int q=2;
	while(q--){
		string s; getline(cin,s);

		stringstream ss;
		ss << s;

		int tmp; char  c;
		while(ss>>tmp){
			ss>>c;
			if(q==1) p.push_back(tmp);
			if(q==0) w.push_back(tmp);
		}

		for(int i=0; i<n; i++){
			wp.push_back({w[i], p[i]});
		}

		sort(wp.begin(), wp.end());

		p.clear(); w.clear();
		for(auto e: wp){
			w.push_back(e.fi);
			p.push_back(e.se);
		}

		solve(n, W, n-1);
	}

	return 0;
}