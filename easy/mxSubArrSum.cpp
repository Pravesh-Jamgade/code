#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back

/*input
8
-1 3 -2 5 3 -5 2 2
*/
typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int n; cin>>n;

	int ans, sum;
	sum=ans=0;

	for(int i=0; i< n; i++){
		int a; cin>>a;
		sum = max(a, sum+a);
		ans = max(ans, sum);
	}
	cout<<sum<<endl;

	return 0;
}