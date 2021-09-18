#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back


typedef long long ll;

int solve(string s, int n, int* max){
	if(n==1){
		return 1;
	}

	int res, max_ending_here = 1;

	for(int i=1; i< n; i++){
		res = solve(s, i, max);
		if(s[i-1] < s[n-1] && res+1 > max_ending_here)
			max_ending_here = res+1;
	}

	if(*max < max_ending_here)
		*max = max_ending_here;

	return max_ending_here;
}

int main(){
	
	freopen("input.txt", "r", stdin);
	string s;
	cin>>s;

	int max = 1;
	solve(s, s.length(), &max);
	return 0;
}