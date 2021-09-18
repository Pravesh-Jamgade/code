#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	char val;
	Node *left, *right;
	Node(char x){
		val = x;
		left = nullptr;
		right = nullptr;
	}
};

string in , pre;

Node* getNode(char x){
	return new Node(x);
}

int getIndex(string in, int inStart, int inEnd, char c){
	for(int i=inStart; i<= inEnd; i++){
		if(in[i] == c) 
			return i;
	}
}

Node* solve(string in, string pre, int inStart, int inEnd){
	static int preIndex = 0;
	if(inStart > inEnd)
		return NULL;

	Node* node = getNode(pre[preIndex++]);

	if(inStart == inEnd)
		return node;

	int inIndex = getIndex(in, inStart, inEnd, node->val);

	node->left = solve(in, pre, inStart, inIndex-1);
	node->right = solve(in, pre, inIndex+1, inEnd);

	return node;
}

void print(Node* node){
	/*inorder*/
	if(node == NULL) return;
	print(node->left);
	cout<<node->val;
	print(node->right);
}

int main(){
	freopen("input.txt", "r", stdin);
	
	getline(cin, in);
	getline(cin, pre);

	int l = in.length();
	Node* root = solve(in, pre, 0, l-1);
	print(root);
	return 0;
}