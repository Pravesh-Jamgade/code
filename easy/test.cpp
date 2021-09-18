#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	int m[]={1,3,5,7,9};
	vector<int> vec(m,m+5);
	auto upper = upper_bound(vec.begin(),vec.end(),5);
	cout<<"upper bound @"<<(upper-vec.begin())<<'\n';

	auto low = lower_bound(vec.begin(),vec.end(),5);
	cout<<"lowe bound @"<<(low-vec.begin())<<'\n';

	vector<int> v;
	upper = upper_bound(v.begin(),v.end(),3);
	cout<<(upper-v.begin())<<endl;

	return 0;
}