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

	int n,m,k;
	cin>>n>>m>>k;

	vector<int>A(n,0),B(m,0);

	for(int i=0; i< n; i++){
		cin>>A[i];
	}

	for(int i=0; i< m; i++){
		cin>>B[i];
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int i,j,p,q;
	i=j=0;
	p=A.size(), q=B.size();

	int c = 0;
	while(i<p and j<q){
		int tx = A[i] - k;
		int ty = A[i] + k;

		if(B[j]>=tx || B[j]<=ty){
			j++; i++; c++;
		}
		if(B[j]<tx || B[j]>ty) i++;
	}

	cout<<c<<endl;
	return 0;
}