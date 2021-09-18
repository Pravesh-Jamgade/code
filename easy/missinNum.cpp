#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int n; cin>>n;

	int sum = n*(n+1)/2;

	int tmp=0;
	int c;
	while(cin>>c){
		tmp+=c;
	}

	sum-=tmp;
	cout<<sum<<endl;

	return 0;
}