#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back



  uint32_t reverseBits(uint32_t n) {
        string res = "";
        while(n){
            int t = n%2;
            n/=2;
            res+=to_string(t);
        }
             
        for(int i=res.length()-1; i<31; i++){
            res+='0';
        }
        
        uint32_t ans = 0;
        int k=0;
        for(int i=res.length()-1; i>-1; i--){
            if(res[i]=='1'){
                int tmp = 1<<k;
                ans+=tmp;
            } 
            k++;
        }

       return ans;
    }


typedef long long ll;
int main(){
	
	freopen("input.txt", "r", stdin);
	uint32_t n; cin>>n;
	cout<<reverseBits(n)<<endl;
	return 0;
}