#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back


typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	string p; cin>>p;

	stack<char> s;
	for(int i=0; p[i]; i++){
		if(p[i] == '(')
			s.push(p[i]);
		else if(p[i] == ')' and !s.empty()){
			s.pop();
		}
	}

	if(s.empty())
		cout<<"yes";
	else cout<<"no";
	return 0;
}