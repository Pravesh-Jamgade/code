#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
/*problem
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
*/

/*input
9
2,7,11,15

0
0,4,3,0

0
-3,4,3,90

*/



typedef long long ll;
int main(){
		
	freopen("input.txt", "r", stdin);
	int t; cin>>t;

	cin.ignore();

	string input; 
	getline(cin, input);

	cout<<input<<endl;

	multimap<int,int>p;

	stringstream ss;
	ss<<input;

	int tmp; char c;

	int i=0;
	while(ss>>tmp){
		p.insert({tmp, i++});
		ss>>c;
	}
	
	vector<int>ans;
	for(auto e: p){
		pii c = e;
		int tmp = t - e.first;
		auto k = p.find(tmp);
		if(k!=p.end()){
			if(k->first == e.first)
				k++;
			ans.push_back(e.second);
			ans.push_back(k->second);
			break;
		}
	}

	for(auto e: ans) cout<<e<<" ";
	return 0;
}