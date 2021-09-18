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
	int n; cin>>n;
	vector<int> a(n, 0);

	map<int,int>mp;
	for(int i=0; i< n; i++){
		cin>>a[i];
		mp[a[i]]=0;
	}

	
	int ans=0;

	for(int i=0,j=0; i< n; ++i){
		while(j<n and mp[a[j]]<1){
			mp[a[j]]++;
			j++;
		}
		ans=max(ans, j-i);
		mp[a[i]]--;
	}

	cout<<ans<<endl;

	return 0;
}