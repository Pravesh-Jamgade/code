#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back

/*input
5
3 8 2 1 5
*/
typedef long long ll;
int main(){
	freopen("input.txt", "r", stdin);
	int n; cin>>n;
	vector<int> v;
	for(int i=0; i< n; i++){
		int a;
		cin>>a;
		int p = upper_bound(v.begin(), v.end(), a)-v.begin();
		cout<<p<<" "<<a<<endl;
		if(p<v.size())
			v[p]=a;
		else
			v.pb(a);
	}

	for(auto e: v){
		cout<<e<<" ";
	}

	return 0;
}