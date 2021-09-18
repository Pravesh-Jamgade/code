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

	string s; getline(cin, s);
	int l,u; l=u=0;

	for(int i=0; i< s.length(); i++){
		if(islower(s[i])) l++;
		else u++;
	}

	string ans;
	for(int i=0; i< s.length(); i++){
		if(l<u){
			ans+=toupper(s[i]);
		}else{
			ans+=tolower(s[i]);
		}
	}
	cout<<ans<<endl;

	return 0;
}