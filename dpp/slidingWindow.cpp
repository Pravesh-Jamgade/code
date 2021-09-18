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


/*   O(k*n)           */
void solve(int *arr, int k, int n){
	int mxN = -1e7;

	for(int i=0; i< n-k+1; i++){
		int c=0;
		for(int j=0; j< k; j++){
			c = c + *(arr+i+j);
		}
		mxN = max(c,mxN);
	}
	cout<<mxN<<endl;
}

/*	O(n)			*/
void solve1(int *arr, int k, int n){
	if(n<k){
		cout<<"invalid";
		return;
	}
	int mxN = 0;
	for(int i=0; i< k; i++){
		mxN += *(arr+i);
	}

	int wsum = mxN;
	for(int i=k; i< n; i++){
		wsum += *(arr+i); // add current element
		wsum -= *(arr+i-k); // remove element at i-k 
		mxN = max(mxN, wsum);
	}

	cout<<mxN<<endl;

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	int arr[] = {1,4,2,10,2,3,1,0,20};
	int k=4;

	int size = sizeof(arr)/sizeof(arr[0]);
	solve(arr, k, size);
	solve1(arr, k , size);
	#endif
	return 0;
}