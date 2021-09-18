#include<bits/stdc++.h>
#include "Line.h"
using namespace std;
using namespace geom;


void allocate(int **p ){
	cout << *p << '\n';
	cout << **p << '\n';
	cout << p << '\n';
}

int main(){
	
	int *ptr;
	*ptr = 9;
	// cout << &ptr << '\n';
	allocate(&ptr);
	// cout<<ptr[0]<<endl;
	return 0;
}
