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
	int n, x;
	cin>>n>>x;

	vector<int> w(n,0);

	int sum = 0;
	for(int i=0; i< n; i++){
		int t; cin>>t;
		sum=sum+t;
	}

	int c= 0;
	while(sum){
		int t = sum/10;
		c+= t;
		sum%=10;
		if(sum<10){
			c+=sum; break;
		}
	}
	cout<<c<<endl;

	return 0;
}