#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define array ar

typedef long long ll;
/*max sum of sub matrix <= k*/


int kadanes(int col[], int& si, int& ei, int n){
	int msf,meh;
	msf=-1e8;
	meh=0;
	for(int i=0; i< n; i++){
		meh+=col[i];
		if(msf<meh){
			if(si==-1) si=i;
			msf=meh;
			ei=i;
		}

		if(meh<=0){
			si=-1;
			meh=0;
		}
	}
	return msf;
}

void print(int l, int r){
	cout<<"("<<l<<","<<r<<")"<<endl;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	vii vec;
	string row;
	while(cin>>row){
		stringstream ss;
		ss<<row;
		int t;
		vi r;
		while(ss>>t){
			char c; ss>>c;
			r.pb(t);
		}
		vec.pb(r);
	}

	int l,r,u,d;
	l=r=u=d=0;

	int rl, rr;
	int ru, rd;
	rl=rr=ru=rd=0;

	int msf=-1e8;

	int col[100] = {0};
	while(l<vec[0].size()){
		r=l;
		for(int i=r; i< vec[0].size(); i++){

			//copy col
			for(int j=0; j< vec.size(); j++){
				if(l==i){
					col[j] = vec[j][i];
				}
				else{
					col[j] = col[j] + vec[j][i];
				}
			}
			// perform kadanes on col
			int si, ei;
			si=ei=-1;
			int meh = kadanes(col, si, ei, vec.size());

			if(msf<meh){
				msf=meh;
				rl=l; rr=i;
				ru=si; rd=ei;
			}

			if(si==-1 and ei==-1) return 0;
		}
		l++;
	}
	
	cout<<msf<<endl;
	print(rl,rr); 
	print(ru,rd);
	return 0;
}