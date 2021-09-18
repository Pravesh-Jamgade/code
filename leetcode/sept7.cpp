#include<bits/stdc++.h>
#include<functional>
using namespace std;
#define vi vector<int>
#define fi first 
#define se second
#define pb push_back
#define pii pair<int,int>
#define ar array
typedef long long ll;

struct Node{
	int val;
	Node* next;
};

Node* getNode(int val){
	Node *newNode = new Node;
	newNode->val = val;
	newNode->next = nullptr;
	return newNode;
}

void print(Node* root){
	while(root){
		cout<<root->val<<", ";
		root=root->next;
	}
}

Node* solve(vi& v){
	Node* root = nullptr;
	for(auto e: v){
		Node* node = getNode(e);
		if(root==nullptr){
			root=node;
		}else{
			node->next = root;
			root=node;
		}
	}
	cout<<"\nprint m,...,3,2,1\n";
	Node*a =root;
	print(a);
	return root;
}

void solve2(Node* root){
	Node*a,*b;
	a=root;

	root=root->next;
	b=root;

	a->next = nullptr;
	cout<<a->val<<", "<<b->val<<", "<<root->val<<endl;

	while(root!=NULL){
		root=root->next;
		b->next=a;
		a=b;
		b=root;
	}

	cout<<"\nprint 1,2,3,..\n";
	print(a);
}
  

class A{
public:
	 int g(){return 1;}
};

class B{
public:
	virtual int g(){return 2;}
};

class C: public A, public B{
public:

};


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	string in;
	getline(cin, in);

	stringstream ss;
	ss << in;

	vi v;
	int tmp;
	while(ss>>tmp){
		v.pb(tmp);
		char c;
		ss>>c; 
	}

	for(auto e: v){
		cout<<e<<" ";
	}
	// make reverse

	Node* head = solve(v);

	// print non-reverse
	solve2(head);
	int a[] = {2,1,0};
	sort(a,a+3);
	for(auto e: a){
		cout<<e<<" ";
	}
	
	cout<<endl;
	 C *aa = new C;
	cout<<aa->g();

	return 0;
}