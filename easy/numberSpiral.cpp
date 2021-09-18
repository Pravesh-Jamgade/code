#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int t;
	cin>>t;

	while(t--){
		ll x,y;
		cin>>x>>y;

		int z = max(x,y);
		int ans = 0;
		if(z == x){
			if(x%2==0){
				ans = z*z - y + 1;
			}
			else{
				ans = (z-1)*(z-1) + y;
			}
		}
		else{
			if(y%2==0){
				ans = (z-1)*(z-1) + x;
			}else{
				ans = z*z - x + 1;
			}
		}

		cout<<ans<<endl;
	}
		
	return 0;
}