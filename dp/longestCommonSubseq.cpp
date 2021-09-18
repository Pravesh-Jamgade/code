#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define ar array
typedef long long ll;

/*
1. subsequence of length i, for a and b
2. compare each of the subsequence and if they equal set maxSubSeq = len
3. i++
*/

void subsequence(int i, int l, string& a, vector<string>& res, string& ans){
	if(l==0) {
		return;
	}

	for(; i< a.length(); i++){
		ans.pb(a[i]);
		subsequence(i+1, l-1, a, res, ans);
		res.pb(ans);
		ans.pop_back();
	}
}

void solve(string& a, string& b){
	cout<<a<<" "<<b<<endl;
	int l = 3;
	vector<string> ra, rb;
	string ans="";
	subsequence(0, l, a, ra, ans);
	ans="";
	subsequence(0, l, b, rb, ans);

	cout<<ra.size()<<" "<<rb.size()<<endl;
	int mxN = -1;
	for(string e: ra){
		for(string a: rb){
			if(e == a){
				int t =  e.length();
				mxN = max(mxN,t);
			}
		}
	}

	cout<<"longest common subsequence: "<<mxN<<endl;
	
}

const int mxN = 100;
static int dp[mxN][mxN] = {0};

int lcs(string& a, string& b, int i, int j){
	
	if(i==0 || j==0){
		dp[i][j] = 0;
		return 0;
	}

	if(dp[i][j] != 0) return dp[i][j];

	if(a[i-1]==b[j-1]){
		dp[i][j]= 1+lcs(a,b,i-1,j-1);
		return dp[i][j];
	}

	dp[i][j]=max(lcs(a,b,i-1,j), lcs(a,b,i,j-1));
	return dp[i][j];
}

string findStr(int al, int bl){
	string ans = "";

	for(int i=0; i<= al; i++){
		for(int j=0; j<= bl; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return ans;
}

void solve2(string& a, string& b){
	cout<<lcs(a,b,a.length(), b.length());

	findStr(a.length(), b.length());
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	string a, b;
	cin>>a>>b;

	solve(a,b);

	solve2(a,b);


	return 0;
}