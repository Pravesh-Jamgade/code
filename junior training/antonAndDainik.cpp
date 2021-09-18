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
	string s;
	cin>>s;
	int a,d; a=d=0;
	for(int i=0; s[i]; i++){
		if(s[i] == 'A')a++;
		else d++;
	}
	if(a<d) cout<<"Dainik";
	else cout<<"Anton";
	return 0;
}