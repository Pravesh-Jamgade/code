#include <bits/stdc++.h>

using namespace std;

string solve(int a, string& A, int& k){
	if(k == 0) return A;
	int l = A.length() - 1;
	int kd = k/l;
	int km = k%l;
	swap(A[0], A[0+kd]);
	solve(a, A, km);
}

int main(){

	int k;
	int n;
	cin>>n>>k;

	string vec;
	int a = 1;
	for(int i=0; i< n; i++){
		vec += to_string(a++);
	}

	cout<<"string: "<<vec<<endl;
	
	a = 0;
	cout<<solve(a, vec, k);

	return 0;
}