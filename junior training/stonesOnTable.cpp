#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define ar array
typedef long long ll;


void solve(){
	int n; cin>>n;
	string str;
	cin>>str;

	int j=0;
	for(int i=1; str[i]; i++){
		if(str[i] == str[j]){
			str[j]='z';
		}
		j++;
	}
	sort(str.begin(), str.end());
	int c = count_if(str.begin(), str.end(), [](char a){
		if(a=='z') return true;
		return false;
	});
	cout<<c<<endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	
	int t; cin>>t;
	while(t--){
		solve();
	}

	#elif ONLINE_JUDGE
	solve();
	#endif



	return 0;
}