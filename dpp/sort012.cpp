#include<bits/stdc++.h>
using namespace std;

int main(){

	freopen("input.txt", "r", stdin);
	string s;
	cin>>s;

	vector<int> a;
	stringstream ss; ss<<s;
	int t; char c;
	while(ss>>t){
		ss>>c;
		a.push_back(t);
	}

	for(auto e: a){
		cout<<e<<" ";
	}
	cout<<'\n';

	int p,q,r;
	p = 0; q = a.size() - 1; r = 0;

	while(r<=q){
		switch(a[r]){
			case 0:
				swap(a[p++], a[r++]);
				break;
			case 1:
				r++;
				break;
			case 2:
				swap(a[r], a[q--]);
				break;
		}
	}

	for(auto e: a){
		cout<<e<<" ";
	}

	return 0;
}