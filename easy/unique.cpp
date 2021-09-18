#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back

/*input
5
2 3 2 2 3*/
typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int n; cin>>n;

	vector<int> vec(n,0);
	for(int i=0; i< n; i++)
		cin>>vec[i];

	sort(vec.begin(), vec.end());	

	int t,c;
	t=1e9;
	c=0;

	for(int e: vec){
		if(t!=e){
			c++;
			t=e;
		}
	}
	cout<<c<<endl;
	return 0;
}