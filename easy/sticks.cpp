#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
/*input
5
2 3 1 5 2
*/

typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int n; cin>>n;
	int a[n];
	for(int i=0; i< n; i++)
		cin>>a[i];

	sort(a, a+n);
	int ans=0;
	for(int i: a){
		ans+= abs(i - a[n/2]);
	}
	cout<<ans<<endl;
	return 0;
}