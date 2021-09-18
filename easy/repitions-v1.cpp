#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	string s; cin>>s;

	int ans=1, c=0;
	char l = 'A';

	for(char d: s){
		if(d == l){
			++c;
			ans = max(c,ans);
		}else{
			l=d;
			c=1;
		}
	}

	cout<<ans<<endl;

	return 0;
}