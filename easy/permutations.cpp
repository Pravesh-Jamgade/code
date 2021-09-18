#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int main(){
	
	freopen("input.txt", "r", stdin);

	int n; cin>>n;

	int a[n];
	for(int i=1; i<=n; i++){
		a[i]=i;
	}	
	for(int i=1; i<= n; i++){
		cout<<a[i]<<"  ";
	}
	cout<<endl;

	for(int i=1; i<=n; i++){
		for(int j=i+1; j<= n; j++){
			// cout<<i<<" "<<j<<" ";
			int d = abs(a[j]-a[i]);
			// cout<<d<<" \n";
			if(d>=2){
				swap(&a[i+1], &a[j]);
				break;
			}
		}
	}

	for(int i=1; i<= n; i++){
		cout<<a[i]<<"  ";
	}

	return 0;
}