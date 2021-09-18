#include<bits/stdc++.h>
using namespace  std;

bool littleTheorem(int p){
	int a = 2;
	while(a%p == 0){
		a = a + rand()%10;
	}

	// a^p
	int r = 1;
	while(p){
		if(p&1)
			r = r*a%99;
		else
			r = r*r%99;

		p>>=1;
	}
	r = r -a;
	if(r%p == 0)return true;
	else return false;
}

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main(){

	freopen("input.txt", "r", stdin);
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;

		if(littleTheorem(x)){
			cout<<x<<" is prime\n";
		}else cout<<x<<" is not prime\n";
	}

	return 0;
}