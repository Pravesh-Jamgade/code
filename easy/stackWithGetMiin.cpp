#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back


stack<int> s;
int miN = 1e9;

int getmiN(){
	return miN;
}

void pop(){
	if(s.top()<miN){
		int x = miN - s.top();
		miN = x;
	}
	s.pop();
}

void push(int& x){
	int t=x;
	if(s.empty()){
		miN = x;
	}
	else{
		if(x<miN){
			t =x - miN;
			miN = x;
		}
	}
	s.push(t);
}

void test(){
	int v[] = {3,2,4,1};
	for(int e: v){
		push(e); 
		cout<<"# "<<e<<" ";
		cout<<getmiN()<<" top:"<<s.top()<<endl;
	}

	pop();
	cout<<getmiN()<<endl;
	pop();
	cout<<getmiN()<<endl;
	pop();
	cout<<getmiN()<<endl;

}