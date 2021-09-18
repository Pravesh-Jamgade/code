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
/*max sum contiguous subarray*/
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	vi vec;
	string str; getline(cin, str);
	stringstream ss;
	ss<<str;

	int tmp;
	while(ss>>tmp){
		char c; ss>>c;
		vec.pb(tmp);
	}

	int msf, meh;
	msf=-1e3;
	meh=0;

	int s,e;
	s=e=-1;
	for(int i=0; i< vec.size(); i++){
		meh += vec[i];
		if(msf<meh){
			if(s==-1) s=i;
			msf=meh;
			e=i;
		}
		if(meh<=0) {
			meh=0;
			s=-1;
		}
	}

	cout<<"index: "<<s<<" to "<<e<<endl;
	cout<<msf<<endl;
	return 0;
}