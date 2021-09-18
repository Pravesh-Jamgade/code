#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define array ar
typedef long long ll;

int solve2(string A, string B, int i, int j){
	if(i==0||j==0) return 0;
	else if(A[i]==B[j]) return 1+solve2(A,B,i-1,j-1);
	else return max(solve2(A,B,i-1,j), solve2(A,B,i,j-1));
}

int solve(string& A, string& B, int x, int y){
	int dp[x+1][y+1]={0};

	for(int i=0; i<= x; i++){
		for(int j=0; j<= y; j++){
			if(i==0||j==0){
				dp[i][j]=0;
				continue;
			}
			else if(A[i-1]==B[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else dp[i][j] = 0;
			
		}
	}

	for(int i=0; i<=x; i++){
		for(int j=0; j<=y; j++){
			cout<<dp[i][j]<<" ";
		}cout<<'\n';

	}
	return dp[x][y]+1;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	string A,B;
	getline(cin,A);
	getline(cin,B);

	stringstream ss;
	ss<<A;
	int c;
	A="";
	while(ss>>c){
		char d; ss>>d;
		A+=to_string(c);
	}

	stringstream xx;
	xx<<B;
	B="";

	while(xx>>c){
		char d; xx>>d;
		B+=to_string(c);
	}

	cout<<A<<'\n'<<B<<'\n';
	
	cout<<solve(A,B,A.size(),B.size())<<endl;

	cout<<solve2(A,B,A.size()-1,B.size()-1)<<endl;
	return 0;
}