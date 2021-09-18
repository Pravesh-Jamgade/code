#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
/*
input
5 3
5 3 7 8 5
4 8 3
*/

typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int n,m; cin>>n>>m;

	vector<int>A(n,0);
	vector<pii> B;
	vector<pii> C;

	for(int i=0; i< n; i++){
		cin>>A[i];
	}

	for(int j=0; j< m; j++){
		int x; cin>>x;
		B.pb({x,j});
	}

	sort(A.begin(), A.end());	
	sort(B.begin(), B.end());	

	int i,j;
	i=j=0;

	while(i<A.size() and j<B.size()){
		if(A[i]<=B[j].fi){
			C.pb({ B[j].se, B[j].fi });
			i++; j++;
		}

		if(A[i]>B[j].fi){
			C.pb({ B[j].se, -1 });
			j++; i++;
			cout<<-1<<endl;
		}
	}

	sort(C.begin(), C.end());

	for(auto e: C){
		cout<<e.se<<endl;
	}
	return 0;
}