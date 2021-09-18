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
	int n; cin>>n;
	string cur, prev;
	cin>>cur;
	prev=cur;
	int c = 0;
	for(int i=1; i< n; i++){
		cin>>cur;
		if(cur!=prev){
			prev=cur; c++;
		}
	}
	c++;

	cout<<c<<endl;
	return 0;
}