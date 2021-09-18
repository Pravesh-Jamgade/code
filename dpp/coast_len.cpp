/*input
5 6
011110
010110
111000
000010
000000
*/
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

vector<string> vec(1001);

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int r,c;
	cin>>r>>c;

	for(int i=0; i< r; i++){
		string in; cin>>in;
		vec.pb(in);
	}

	for(auto e: vec){
		cout<<e<<"\n";
	}

	return 0;
}
