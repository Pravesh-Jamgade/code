#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define  ar array
typedef long long ll;

class Node{
public:
	Node(int i){v=i; l=r=NULL;}
	Node* l, *r;
	int v;
	Node* find(int x){
		Node* tmp;
		if(v==x) return this;
		else if(x<v and l!=nullptr){
			tmp= l->find(x);
		}
		else if(x>v and r!=nullptr){
			tmp=r->find(x);
		}

		if(tmp->v!=x || tmp==nullptr){
			tmp->v=0;
		}
		return tmp;
	}
};

Node* getNode(int i){
	Node* node= new Node(i);
	return node;
}
Node* C(int i, Node* head){
	if(head==NULL){
		Node* node = getNode(i);
		return node;
	}
	if(i<head->v){
		head->l=C(i,head->l);
		return head;
	}
	else{
		head->r=C(i,head->r);
		return head;
	}
	return NULL;
}

void it(Node* node){
	if(node==NULL) return ;
	it(node->l);
	cout<<node->v;
	it(node->r);
}

class A{

public:
	int v(){return 1;}
	~A(){cout<<"A";}
};

class B{
public:
	int v(){return 2;}
	~B(){cout<<"B";}
};


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	// int a[] = {7,4,5,3,8,9,6};

	// Node* head = NULL;
	// for(int i: a){
	// 	head = C(i,head);
	// }

	// // it(head);
	// Node* ans = head->find(10);

	// if(ans!=NULL)
	// 	cout<<ans->v<<endl;
	// else cout<<"jell";

	// Node* t;
	// int a=5;
	// int *p;
	// p=&a;

	// cout<<p<<endl;
	// // cout<<t->v<<endl;
	// A*o = new B();
	// cout<<o->v();
	// cout<<(2>>1)<<endl;

	A a1;
	B b2;
	return 0;
}