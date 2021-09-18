#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

vector<int> g[MAX];

// bool dfs(int c, int p, int t){
//     vis[c] = true;
//     if(t == c) return true;
//     for(auto child: g[c]){
//         if(child == p) continue;
//         if(dfs(child, c, t)){
//             return true;
//         }
//     }
//     return false;
// }

int main(){

    /*int r, e;

    cin>>r;

    vector<int> ri;
    for(int i=0; i< r; i++){
        cin>>ri[i];
    }

    cin>>e;
    for(int i=0; i< e; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int vis[r];
    for(int i=0; i< r; i++){
        vis[i] = false;
    }

    int A,B;
    cin>>A>>B;*/
    // dfs(A, -1, B);

    unordered_multimap<int, int> b;
    unordered_multimap<int, unordered_multimap<int, int>>a ;
   a.insert({1, b});


    for(auto i: a){
        cout<<i.second<<" ";
    }
    return 0;
}
