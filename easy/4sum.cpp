#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unordered_set<int> usi;
typedef unordered_set<string> uss;
typedef multimap<int,int> mi;
typedef multimap<int, mi> mmi;
typedef vector<vector<int>> vvi;

/*input
0
1,0,-1,0,-2,2
*/

string getString(vi& a){
	string t = "";
	for(auto e: a){
		t+= to_string(e);
	}
	return t;
}

vector<vector<int>> ans;
void solve(vi& p, int t){

	multimap<int, vector<int>> mv;

	for(int i=0; i< p.size(); i++){
		for(int j=i+1; j< p.size(); j++){
			int t = p[i] + p[j];
			vector<int> k;
			k.pb(i);
			k.pb(j);
			mv.insert({t, k});
		}
	}

	uss mpp;
	
	for(auto pair: mv){
		int tmp = -(t-pair.fi);// for a sum find opposite sum
		auto all = mv.find(tmp);
		if(all!=mv.end()){ // if opposite sum exist [a+b] = find[ -(t-c-d) ]
			vector<int> res;
			auto e= pair.se;
			res.pb(all->second[0]);
			res.pb(all->second[1]);

			usi mppi;
			mppi.insert(all->second[0]);
			mppi.insert(all->second[1]);
			
			if(mppi.find(e[0])==mppi.end() and mppi.find(e[1]) == mppi.end() and ){
				res.pb(e[0]);
				res.pb(e[1]);
			}
			

			sort(res.begin(), res.end());
			string s = getString(res);

			if(mpp.find(s)==mpp.end()){
				mpp.insert(s);
				ans.pb(res);
			}
		}
	}



}

int main(){
	
	freopen("input.txt", "r", stdin);
	int t; cin>>t;
	cin.ignore();
	string s; getline(cin, s);

	vi p;
	stringstream ss;
	ss << s;

	int tmp; char c;
	while(ss>>tmp){
		p.pb(tmp); ss>>c;
	}

	for(auto e: p){
		cout<<e<<" ";
	}
	cout<<endl;

	solve(p, t);

	for(auto row: ans){
		for(auto e: row){
			cout<<e<<" ";
		}
		cout<<endl;
	}

	return 0;
}