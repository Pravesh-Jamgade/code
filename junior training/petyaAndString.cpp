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

int get(char c){
	int t;	
	if(c>='A' and c<='Z') t=c-'A';
	if(c>='a' and c<='z') t=c-'a';
	return t;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif


		string A,B;
		getline(cin, A);
		getline(cin, B);
		
		vector<int>a,b;
		a.resize(A.length(), 0);
		b.resize(B.length(), 0);
		for(int i=0; i< A.length(); i++){
			a[i]=get(A[i]);
		}

		for(int i=0; i< B.length(); i++){
			b[i]=get(B[i]);
		}

		int st=0;
		for(int i=0 ;i< A.length() and i< B.length(); i++){
			if(a[i] > b[i]){st=1; break;}
			if(a[i]<b[i]){st=-1; break;}
		}
		cout<<st<<endl;

	return 0;
}