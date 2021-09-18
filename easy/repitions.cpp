#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);

	string s;
	cin>>s;

	vector<int> a(4,0); // ACGT
	vector<int> b(4,0); // ACGT

	int k = -1;
	int pk = -1;
	for(int i=0; i< s.length(); i++){
		
		if(s[i]=='A') 	   k =0;
		else if(s[i]=='C') k =1;
		else if(s[i]=='G') k =2;
		else if(s[i]=='T') k =3;


		a[k]++;
		if(i>0 and s[i]!=s[i-1]){
			b[pk] = max(a[pk], b[pk]);
			a[pk] = 0;
		}
		pk=k;	
	}

	b[pk] = max(a[pk], b[pk]);

	int mxI = -1; int mxE = -1;
	for(int i=0; i< 4; i++){
		if(b[i]>mxE){
			mxE = b[i];
			mxI = i;
		}
	}

	cout<<mxE<<endl;
	return 0;
}