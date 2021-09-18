#include<bits/stdc++.h>
using namespace std;


/*input
3 3 4
1 2 5 10
1 2 2 1 2
1 3 1 3
2 3 1 4
*/


#define fi first
#define se second
typedef pair<int, int> pi;
typedef pair<int, pi> pii;


const int  mxN = 1e3+1;
vector<pii> g;

bool root(int x, vector<int>&base){
	while(x!=base[x]){
		x = base[x];
	}
	return x;
}

void add(int x, int y, vector<int>&base){
	int tx = root(x, base);
	int ty = root(y, base);
	base[tx] = base[ty];
}

int main(){

	freopen("input.txt", "r", stdin);

	int n,m,k;
	cin>>n>>m>>k;

	vector<int> c(k, 0);
	for(int i=0; i< k; i++){
		cin>>c[i];
	}

	for(int i=0; i< m; i++){
		int x,y,cn;
		cin>>x>>y>>cn;

		vector<int>cost(cn, 0);
		
		for(int j=0; j< cn; j++){
			cin>>cost[j];
		}

		sort(cost.begin(), cost.end(), [](int a,int b){ return a<b;});

		g.push_back({cost[0], {x,y}});

	}

	sort(g.begin(), g.end(), [](pii a, pii b){ return a.fi<b.fi;});


	vector<int> base(n);
	for(int i=0; i<= n; i++)
		base[i]=i;

	int cost = 0;
	for(int i=0; i< m; i++){
		pii p = g[i];
		int x,y,c;
		c = p.fi; 
		x=p.se.fi; 
		y=p.se.se;

		cost = cost + c;
	}

	cout<<"min cost: "<<cost<<endl;
	// for(auto e: g){
	// 	pi k = e.se;
	// 	cout<<e.fi;
	// 	cout<<k.fi;
	// 	cout<<k.se<<endl;
	// }
	return 0;
}