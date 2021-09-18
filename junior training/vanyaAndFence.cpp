#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back


typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int n, h;
	cin>>n>>h;

	int sum = 0;
	for(int i=0; i< n; i++){
		int t; cin>>t;
		if(t-h <= 0) sum+=1;
		else sum+=2;
	}
	cout<< sum <<endl;
	return 0;
}