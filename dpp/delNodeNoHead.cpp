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
	Node* next = NULL;
	int val;
	int a= 1e8;
};

Node* getNode(int v){
	Node* node = new Node;
	node->val = v;
	node->next = nullptr;
	return node;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int arr[] = {1,2,3,4,5};

	Node* head = nullptr;
	Node* tmp = nullptr;
	for(auto e: arr){
		Node* node= new Node;
		node = getNode(e);
		if(!head){
			head = node;
			tmp = node;
		}
		else{
			tmp->next = node;
			tmp=tmp->next;
		}
	}

	Node* run = head;
	while(run){
		cout<<run->val<<" " ;
		run=run->next;
	}

	run = head;

	Node* del = head->next;
	del = del->next;
	cout<<"\nto be deleted: "<<del->val<<endl;

	Node* p,*q;
	p= del;
	q= del;

	while(q->next != nullptr){
		tmp = q;
		q=q->next;
	}

	int t = q->val;
	q->val = p->val;
	p->val = t;
	tmp->next = nullptr;
	delete q;
	while(run){
		cout<<run->val<<" ";
		run=run->next;
	}

	cout<<endl;
	sort(arr, arr+5, [](int a, int b){
		return a>b;
	});
	for(auto e: arr){
		cout<<e<<" ";
	}

	vi app;
	app.push_back(1908);
	return 0;
}