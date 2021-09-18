#include<bits/stdc++.h>
using namespace std;


/*input
6
sugarloaf
maracana
copacabana
ipanema
corcovado
lapa
ipanema copacabana
copacabana sugarloaf
ipanema sugarloaf
maracana lapa
sugarloaf maracana
corcovado sugarloaf
lapa corcovado*/
const int mxN = 1e3;
map<string, int> mp;
map<int, string> pm;
vector<int> g[mxN];
	

class M{
public:
	vector<bool> vis, AP;
	vector<int> parent, disc, low;
	int time;
	int k;
	M(int n){
		vis.resize(n, false);
		AP.resize(n, false);
		disc.resize(n, 0);
		low.resize(n, 0);
		parent.resize(n, 0);
		k = n;
		for(int i=0; i< n; i++){
			parent[i]=i;
		}
		parent[0] = -1;
		time = 0;
		
	}

	void update(int s, int d, int c){
		if(parent[s] == -1 and c>1)
			AP[s] = true;
		if(parent[s] != -1 and low[s]>= disc[d])
			AP[s] = true;
	}

	void set(int s){
		low[s]=disc[s]=time++;
		vis[s] = true;
	}

	void output(){
		cout<<"Cameras at: ";
		for(int i=0; i< k; i++){
			if(AP[i]){
				cout<<i<<"= ";
				auto it = pm.find(i);
				if(it!=pm.end()){
					cout<<it->second<<", ";
				}

			} 
		}cout<<endl;
	}
};

void dfs(int s, M& m){
	m.set(s);
	int child = 0;
	for(auto d: g[s]){
		if(!m.vis[d]){
			child += 1;
			m.parent[d] = s;
			dfs(d, m);
			m.low[s] = min(m.low[d], m.low[s]);
			m.update(s, d, child);
		}
		else if(m.parent[s]!=d){
			m.low[s] = min(m.disc[d], m.low[s]);
		}
	}
}

int main(){

	freopen("input.txt", "r", stdin);
	int n;
	cin>>n;

	for(int i=0; i< n; i++){
		string t; cin>>t;
		mp.insert({t, i});
		pm.insert({i, t});
	}

	// for(auto e: mp){
	// 	cout<<e.first<<" @ "<<e.second<<endl;
	// }

	string x,y;
	while(cin>>x>>y){
		auto p = mp.find(x);
		auto q = mp.find(y);
		if(p!= mp.end() and q!=mp.end()){
			g[p->second].push_back(q->second);
			g[q->second].push_back(p->second);
		}

	}

	M m(n);
	dfs(0, m);
	m.output();

	for(int i=0; i< n; i++){
		cout<<i<<" : ";
		for(auto e: g[i]){
			cout<<e<<" ";
		}
		cout<<endl;
	}
	return 0;
}