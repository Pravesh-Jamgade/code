#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back

typedef long long ll;

const int mxN = 1e6;

vector<int> vec;

void solve(int n){
	vec[0] = vec[1] = 1;
	for(int i=2; i<= n; i++){
		for(int j=0; j<= 6; j++){
			if(j>i) continue;
			vec[i] = vec[i] + vec[i-j];
		}
	}

	for(int i=0; i<= n; i++){
		cout<<vec[i]<<" # of ways for :"<<i<<" \n";
	}
}

int main(){
	
	freopen("input.txt", "r", stdin);
	int n; cin>>n;
	vec.resize(n, 0);
	solve(n);
	return 0;
}