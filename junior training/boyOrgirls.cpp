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
	string s; getline(cin,s);

	vi a(26,0);

	for(int i=0; i< s.length(); i++){
		if(a[s[i]-'a'] == 0) a[s[i]-'a']++;
	}
	
	int sum = accumulate(a.begin(), a.end(), 0);
	if(sum%2==0) cout<<"CHAT WITH HER!";
	else cout<<"IGNORE HIM!";

	return 0;
}