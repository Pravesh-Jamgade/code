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
int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	

	int a,b;
	cin>>a>>b;
	if(a>b) 
	{
		cout<<0<<endl;
		return 0;
	}

	int k=0;
	while(a<=b){
		a=3*a;; b=2*b;
		k++;
	}

	cout<<k<<endl;
	return 0;
}