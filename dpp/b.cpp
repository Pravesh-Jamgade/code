#include<bits/stdc++.h>
using namespace std;

hash<string> hashFunc;
set<string> hp;
void solve(int a, string& s, vector<string>& r, string in){
    for(int i=a; i< in.length(); i++){
        s += in[i];
        string tmp = to_string(hashFunc(s));
        if(hp.find(tmp) != hp.end()) return;
        else{
            hp.insert(tmp);
            r.push_back(s);
        }
        return solve(i+1, s, r, in);
    }
}

int count_sets (int N, string in) {
    vector<string> vec;
    for(int i=0; i< in.length(); i++){
        string str = "";
        solve(i, str, vec, in);
    }
    
    hp.clear();
    vector<string> nl;
    for(auto e: vec){
        string t = "";
        if(e.length() == 1){
            t = to_string(hashFunc(e));
            hp.insert(t);
            nl.push_back(e);
        }else{
            vector<char> c;

            for(int i=0; e[i]; i++){
                c.push_back(e[i]);
            }

            vector<char>::iterator p = unique(c.begin(), c.end());
            c.resize(distance(c.begin(), p));
            string str = "";
            for(int i=0; i< c.size(); i++){
                str += c[i];
            }

            t = to_string(hashFunc(str));
            if(hp.find(t) == hp.end()){
                hp.insert(t);
                nl.push_back(str);
            }
        }
    }
    hp.clear();
    return nl.size();
}

int main() {

string a = "a";
cout<<a.substr(0);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // int T;
    // cin >> T;
    // for(int t_i = 0; t_i < T; t_i++)
    // {
    //     int N;
    //     cin >> N;
    //     string A;
    //     cin >> A;

    //     int out_;
    //     out_ = count_sets(N, A);
    //     cout << out_;
    //     cout << "\n";
    // }
}