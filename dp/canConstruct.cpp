#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define array ar
typedef long long ll;


/* Bruteforce
time complexity => len(target)=n, len(dict)=m
O(m^n) at max there will be tree height of n
at each level i, tree branches to m^i

space complexity=> call stack at max take O(n)
but on each level store substring say in worst case of len =n;
O(n*n)

DP
O(m*n^2) time
O(n^2) space
*/
map<string, bool> dp;

bool solve(string& t, vector<string>& dict, vi& index){
	if(t=="") return true;
	for(int i=0; i< dict.size(); i++){
		if(t.length() < dict[i].length()) continue;
		string tmp = t.substr(0, dict[i].length());
		string nstr = t.substr(dict[i].length());
		if(tmp==dict[i]){
			if(solve(nstr, dict, index) or dp[t]==true){
				dp[t]=true;
				
				index.pb(i);
				return true;
			}
		}
	}
	dp[t]=false;
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	string target;
	vector<string> dict;
	getline(cin, target);

	string line;
	getline(cin, line);

	size_t start,end;
	start=end=0;

	while(start<line.length())
	{	
		if((start = line.find('"', start)) == string::npos)
			break;
		if( (end=line.find('"', start+1)) == string::npos)
			break;
		string tmp = line.substr(start+1, end-start-1);
		dict.pb(tmp);
		start=end+1;
	}

	vi index;
	solve(target, dict, index);

	reverse(index.begin(), index.end());
	string ans;
	for(int i=0; i< index.size(); i++){

		ans+=dict[index[i]];
	}

	cout<<ans<<endl;

	return 0;
}