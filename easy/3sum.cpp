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
typedef map<int,int> mii;
typedef vector<vector<int>> vvi;

/*input
-1,0,1,2,-1,-4
*/

mii mp;
vi rs;
vvi res;
uss us;

string getString(vector<int> s){
	string tmp="";
	for(auto e: s){
		tmp += to_string(e);
	}
	return tmp;
}

void solve(vi& p){

	int i=0;
	for(auto e: p){
		mp.insert({e, i++});
	}

	for(int i=0; i< p.size(); i++){
		for(int j=i+1; j< p.size(); j++){
			int tmp = -(p[i] + p[j]);

			if(mp.find(tmp)!=mp.end()){

				int ind = mp.find(tmp)->se;
				rs.pb(p[i]); rs.pb(p[j]); rs.pb(p[ind]);
				sort(rs.begin(), rs.end());

				string s = getString(rs);
				if( us.find(s)==us.end() and i!=ind and j!=ind){
					us.insert(s);
					res.pb(rs); 
				}
				rs.clear();
			}
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);

	string input; 
	vi p;

	getline(cin, input);

	stringstream ss;
	ss<<input;

	int tmp; char c;
	while(ss>>tmp){
		p.push_back(tmp); 
		ss>>c;
	}

	/* solve */

	unique(p.begin(), p.end());
	solve(p);

	for(auto row: res){
		for(auto e: row){
			cout<<e<<" ";
		}
		cout<<endl;
	}
	return 0;
}