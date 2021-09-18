#include<bits/stdc++.h>
using namespace std;


struct Node{
	Node* left, *right; int v;
};

void inorder(Node* node){
	if(node == nullptr) return;
	inorder(node->left);
	cout<<node->v<<" ";
	inorder(node->right);
}

Node* getNode(int c){
	Node* node = new Node;
	node->left = node->right = nullptr;
	node->v = c;
	return node;
}

Node* build(Node* node, Node* root){
	if(!root) return node;
	else{
		if(root->v > node->v){
			root->left = build(node, root->left);
		}
		else{
			root->right = build(node, root->right);
		}
	}
	return root;
}

int getHeight(Node* node){
	if(!node) return 0;
	return 1 + max(getHeight(node->left), getHeight(node->right));
}

void printByLevel(int i, Node* node){
	if(!node) {
		cout<<" ";
		return ;
	}

	if(i==0){
		cout<<node->v<<" ";
	}
	else{
		printByLevel(i-1, node->left);
		printByLevel(i-1, node->right);
	}
}

void levelPrint(Node* node){
	int h = getHeight(node);
	for(int i=0; i< h; i++){
		printByLevel(i, node);
		cout<<endl;
	}
}

void printLeftView(Node* node, int l, int* m){
	if(node==NULL) return;
	if(*m<l){
		cout<<node->v<<" ";
		*m = l;
	}

	printLeftView(node->left, l+1, m);
	printLeftView(node->right, l+1, m);
}

void leftView(Node* node){
	int m = 0;
	printLeftView(node, 1, &m);
}

void mirror(Node* node){
	if(node == NULL)
		return ;
	else{
		Node* tmp=nullptr;
		mirror(node->left);
		mirror(node->right);

		tmp = node->left;
		node->left = node->right;
		node->right = tmp;
	}
}

bool isSame(Node* a, Node* b){

	if(b==nullptr and a==nullptr) {
		return true;
	}
	if(!a and !b and isSame(a->left, b->left) and isSame(a->right, b->right)){
		return true;
	}
	return false;
}

bool isFoldable(Node* node){
	bool res;
	if(node==NULL)
		return true;
	mirror(node->left);
	res = isSame(node->left, node->right);
	mirror(node->left);
	return res;
}



vector<int> a;

int main(){

	freopen("input.txt", "r", stdin);
	string in;
	getline(cin, in);

	stringstream ss;
	ss << in;

	int tmp; char c;
	while(ss>>tmp){
		a.push_back(tmp);
		ss>>c;
	}

	for(auto e: a){
		cout<<e<<",";
	}
	cout<<endl;
	
	Node* root = nullptr;

	for(int i=0; i< a.size(); i++){
		Node* node = getNode(a[i]);
		root = build(node, root);
	}

	cout<<"\ninorder: ";
	inorder(root);
	cout<<"\nheight: "<<getHeight(root)<<endl;

	cout<<"\nlevel print: ";
	levelPrint(root);

	cout<<"\nprint left view: ";
	leftView(root);

	cout<<"\nmirro tree: ";
	mirror(root);
	levelPrint(root);

	cout<<"\nreverse mirror: ";
	mirror(root);
	levelPrint(root);


	cout<<"\nfoldable: "<<isFoldable(root)<<endl;
	
	cout<<"\nprint right view: ";
	mirror(root);
	leftView(root);
	mirror(root);



	return 0;
}