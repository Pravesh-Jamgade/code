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
	
	int r,c; r=c=-1;
	for(int i=0 ;i< 5; i++){
		for(int j=0; j< 5; j++){
			int t; cin>>t; if(t){
				r=i; c=j;
				break;
			}
		}
	}

	int m=0;
	if(r!=-1)
	 m=abs(r-2) + abs(c-2);
	cout<<m<<endl;

	return 0;
}