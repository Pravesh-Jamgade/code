#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back

/*Input:
4 8
2 7 5 1*/

typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);

	map<int,int> m;

	int n,x;
	cin>>n>>x;

	for(int i=0; i< n; i++){
		int a; cin>>a;
		if(m.find(x-a)!=m.end()){
			cout<<m[x-a]+1<<' '<<i+1;
			return 0;
		}
		m[a]=i;
	}
	cout<<"IMPOSSIBLE";
	return 0;
}