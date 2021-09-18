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

int part(vi& v, int y, int z){
	int p = v[z];
	int i = y-1;
	for(int j=y; j<=z-1; j++){
		if(v[j]<p){
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i+1], v[z]);
	return i+1;
}

void quick(vi& v, int y, int z){

	if(y<z){
		int p = part(v,y,z);
		quick(v,y,p-1);
		quick(v,p+1,z);
	}

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n; cin>>n;
	vi v(n,0);
	for(int i=0; i< n; i++){
		cin>>v[i];
	}
	
	quick(v, 0, n-1);

	for(auto e: v){
		cout<<e<<" ";
	}
	
	return 0;
}