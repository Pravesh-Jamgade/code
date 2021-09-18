#include<bits/stdc++.h>
using namespace std;

vector<int> all;

void solve(int n){
	int d = n;
	for(int i=2; i*i<= n; i++){
		if(d%i==0){
			all.push_back(i);
		}
	}
}


pair<int,int> solve2(int n){
	int d = n;
	int m = -1;
	for(int i=2; i*i<= n; i++){
		if(d%i==0){
			if(m < i) m = i;
			all.push_back(i);
		}
	}
	return {m, all.size()};
}

int main(){
	freopen("input.txt", "r", stdin);
	int n;
	cin>>n;
	solve(n);
	cout<<"prime factors: ";
	for(auto e: all){
		cout<<e<<", ";
	}

	all.clear();

	cout<<'\n';
	pair<int,int> l = solve2(n);
	cout<<"size and max: ";
	cout<<l.second<<" "<<l.first<<endl;
	return 0;
}