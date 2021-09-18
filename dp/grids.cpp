#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back

/*input
4
....
.*..
...*
*...
*/

const int mxN = 1e3;
int arr[mxN][mxN];
typedef long long ll;

int main(){
	
	freopen("input.txt", "r", stdin);
	int n; cin>>n;
	for(int i=0; i< n; i++){
		for(int j=0; j< n; j++){
			char c; cin>>c;
			if(c == '.') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}

	arr[0][0] = 1;

	for(int i=0; i< n; i++){
		for(int j=0; j< n; j++){
			if(arr[i][j] == 0 || (i==0 and j==0) ) continue;
			if(i==0) arr[i][j]=arr[i][j-1];
			if(j==0) arr[i][j]=arr[i-1][j];
			else{
				arr[i][j] = arr[i-1][j] + arr[i][j-1];
			}
		}
	}

	for(int i=0; i< n; i++){
		for(int j=0; j< n; j++){
			cout<<arr[i][j]<<" ";
		}cout<<endl;
	}
	return 0;
}