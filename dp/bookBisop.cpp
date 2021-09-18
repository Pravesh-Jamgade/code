#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back

/*input
4 10
4 8 5 3
5 12 8 1
*/
typedef long long ll;

int main(){
	
	freopen("input.txt", "r", stdin);
	int n, x;
	cin>>n>>x;

	vector<int> h(n,0), s(n,0);

	for(int i=0; i< n; i++){
		cin>>h[i];
	}

	for(int i=0; i< n; i++){
		cin>>s[i];
	}

	vector<int> dp(x+1, 0);

	for(int i=0; i< n; i++){
		for(int j=x; j>= h[i]; --j){
			dp[j] = max(dp[j], dp[j-h[i]] + s[i]);
		}
	}

	cout<<dp[x]<<endl;
	return 0;
}