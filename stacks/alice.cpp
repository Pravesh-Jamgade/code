#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	string a;
	getline(cin,a);
	cout<<a<<endl;

	stack<char> st;

	string mid, l, r;
	mid = l = r = "";
	int i=0;

	for(i=0; i< a.length(); i++){
		st.push(a[i]);
		if(a[i]=='\\'){
			st.pop();
			while(st.top() != '/'){
				mid = mid + st.top();
				st.pop();
			}
			break;
		}
	}

	while(!st.empty()){
		if(st.top() == '/'){
			st.pop(); continue;
		} 
		l+=st.top(); st.pop();
	}
	reverse(l.begin(), l.end());
	l+=mid;


	for(; i< a.length(); i++){
		if(a[i]!='\\')
			r+=a[i];
	}

	l+=r;

	reverse(l.begin(), l.end());
	cout<<l<<endl;

	return 0;
}