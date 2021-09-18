#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define ar array
typedef long long ll;

/*
1,3

Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6*/

const int mxN = 21;
int dp[mxN] = {0};


void solve2(int k, int& sum, vi& row, vvi& res, vi& v){

	if(row.size() != 0){
		int tmp = 0;
		if(row.size() <=1){
			tmp = row[0];
		}
		else{
			for(int i=0; i< row.size(); i++){
				tmp = tmp ^ row[i];
			}
		}
		
		sum += tmp;
		res.pb(row);
	}
	for(int i=k; i< v.size(); i++){
		row.pb(v[i]);
		solve2(i+1, sum, row, res, v);
		row.pop_back();
	}
}

void solve(){
	string str;
	cin>>str;
	stringstream ss;
	ss<<str;
	int tmp;

	vi v;
	while(ss>>tmp){
		char c; ss>>c;
		v.pb(tmp);
	}

	int sum = 0;
	vvi res;
	vi row;
	solve2(0, sum, row, res, v);
	cout<<"xor sum is: "<<sum<<endl;
	for(int i=0; i< res.size(); i++){
		for(int j=0; j< res[i].size(); j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	int t; cin>>t;
	while(t--){
		solve();
	}
	#endif

	return 0;
}