#include<bits/stdc++.h>
using namespace std;

/*input
5
3 2 5 1 7
*/
typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int n; cin>>n;
	vector<int> vec(n);

	int mx = 0, ans = 0;
	for(int i=0; i< n; i++){
		int t; cin>>t;
		mx = max(t,mx);
		t = mx - t;
		ans+=t;
	}

	cout<<ans<<endl;

	return 0;
}