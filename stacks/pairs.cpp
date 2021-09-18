#include<bits/stdc++.h>
using namespace std;

/*input
5
1 2 3 4 5
*/

typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int n; cin>>n;

	stack<int> s;
	int c = 0;
	int a;
	
	while(cin>>a){
		while(!s.empty() and a>s.top()){
			s.pop(); c++;
		}
		if(!s.empty()) c++;
		s.push(a);
	}

	cout<<c<<endl;

	return 0;
}