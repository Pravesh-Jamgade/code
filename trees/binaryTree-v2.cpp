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
	int v; Node* left, *right;
};

Node* getNode(int i){
	Node* node =new Node();
	node->v=i;
	node->left=node->right=nullptr;
	return node;
}

Node* build(Node* root, int e){
	if(!root){
		root = getNode(e);
		return root;
	}
	else{
		if(e > root->v){
			root->right = build(root->right, e);
		}
		else{
			root->left = build(root->left, e);
		}
	}
	return root;
}

void inorder(Node* root, vector<int>& in){
	if(root == NULL) return;
	inorder(root->left, in);
	cout<<root->v;
	in.pb(root->v);
	inorder(root->right, in);
}

void preorder(Node* root, vector<int>& pre){
	if(root == NULL) return;
	cout<<root->v;
	pre.pb(root->v);
	preorder(root->left, pre);
	preorder(root->right, pre);
}


void postorder(Node* root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->v<<" ";
}

int search(vi& in, int l, int r, int v){
	int m = l + (r-l)/2;
	if(in[m] == v) return m;

	if(in[m] > v){
		return search(in, m+1, r, v);
	}
	else return search(in, l, m-1, v);
}

Node* PreAndIn(Node* root, vector<int> p, vector<int> in, int l, int r){
	static int preIndex = 0;
	if(l>r) return NULL;
	Node* node=getNode(p[preIndex++]);
	if(l==r) return node;
	int index = search(in, l, r, node->v);
	node->left = PreAndIn(root, p, in, l, index-1);
	node->right = PreAndIn(root, p, in, index+1, r);
	return node;
}

bool isSame(Node* a, Node* b){

	if(a==nullptr and b==nullptr) {
		return true;
	}

	else if(a and b and isSame(a->left, b->left) and isSame(a->right, b->right)){
		return true;
	}
	return false;
}

Node* del(Node* root, int key){
	if(root==NULL){
		return root;
	}
	if(root->v < key){
		root->right = del(root->right, key);
		return root;
	}
	else if(root->v > key){
		root->left = del(root->left, key);
		return root;
	}else{
		if(root->left==nullptr and root->right != nullptr){
			Node* tmp=root->right;
			delete root;
			return tmp;
		}
		else{
			
			if(root->left!=nullptr and root->right == nullptr){
				Node* tmp=root->left;
				delete root;
				return tmp;
			}

			else{
				if(!root) return root;

				Node* tmp=root->left;
				while(tmp->right) tmp=tmp->right; 
				root->v=tmp->v;
				tmp->v=key;
				root->left = del(root->left, key);
				return root;
			}

		}
	}

	return root;
}

int height(Node* root){
	if(root==nullptr) return 0;
	return 1+max(height(root->left), height(root->right));
}


int diameter(Node* root){
	if(root==nullptr) return 0;

	int lh = height(root->left);
	int rh = height(root->right);

	int ld = diameter(root->left);
	int rd = diameter(root->right);

	int m = max(ld, rd);
	return max(lh+rh+1, m);
}

void mirror(Node* root){
	if(root==nullptr) return;
	else{
		Node* tmp = nullptr;
		mirror(root->left);
		mirror(root->right);
		tmp=root->left;
		root->right = root->left;
		root->left = tmp;
	}
}


bool isSameInValue(Node* a, Node* b){
	if(!a and !b) return true;
	if(a and b and isSameInValue(a->left, b->left) and isSameInValue(a->right, b->right)){
		if(a->v == b->v) return true;
		return false;
	}
	return false;
}

bool findPath(Node* root, vi& path, int k){
	if(!root) return false;
	path.pb(root->v);
	if(k == root->v) return true;
	if( (root->left and findPath(root->left, path, k)) || (root->right and findPath(root->right, path, k))){
		return true;
	}

	path.pop_back();
	return false;
}

bool findLCA(Node* root, int x, int y){
	vi p,q;
	if(!findPath(root,p,x) || !findPath(root,q,y))
		return false;

	reverse(q.begin(), q.end());
	// reverse(q.begin(), p.end());
	int tmp = -1;
	for(int i=0; i< p.size() and i< q.size(); i++){
		if(tmp == -1 and p[i]==q[i]){
			tmp = q[i]; break;
		}
	}
	cout<<"common ancestor: "<<tmp<<endl;
	return true;
}

vector<int> preIter(Node* root){
	vi v;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* tmp = st.top();
        st.pop();

        v.pb(tmp->v); 
       
        if(tmp->right) st.push(tmp->right);
        if(tmp->left) st.push(tmp->left);
    }

    for(auto e: v){
    	cout<<e;
    }
    return v;
}

class A{
public:
	A(){
		cout<<"A\n";
	}
};

class B{
public:
	B(){
		cout<<"B\n";
	}
};

class C{
public:
	C(){
		cout<<"C\n";
	}
};

class X: public A, public B, public C{
public:
	X(){
		cout<<"X\n";
	}
};


struct Y{
	int a=109;
	Y(int i){
		this->a = i;
	}
};

int countDuplicate(vector<int> numbers) {
    int c = 0;
    sort(numbers.begin(), numbers.end());

    stack<int> s;
    s.push(numbers[0]);
    numbers.pb(1001);

    int i = 1;
    int t = 0;
    int p = 0;
    while(i< numbers.size()){
        if(s.top() == numbers[i]){
            s.pop();
            c++;
        }else{
        	if(p!=c){
        		p=c;
        		t++;
        	}
        }
        s.push(numbers[i++]);
    }
    return t;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int arr[] = {6,4,8,3,5,7,9};
	int arr2[] = {4,8,3,5,7,9};

	Node* root = NULL;
	for(int i: arr){
		root = build(root, i);
	}

	Node* root2 = NULL;
	for(int i: arr2){
		root2 = build(root2, i);
	}


	vi in, pre;
	inorder(root, in); cout<<"\n";
	preorder(root, pre);
	Node* newRoot = PreAndIn(root, pre, in, 0, pre.size()-1);
	cout<<endl;

	vi preAndIn;
	inorder(newRoot, preAndIn); cout<<endl;
	cout<<isSame(root, root2)<<endl;

	int key = 5;
	inorder(root2, pre);
	cout<<endl;
	del(root2, key);
	inorder(root2, pre);

	cout<<endl;
	cout<<height(root)<<" "<<height(root2)<<endl;
	cout<<diameter(root)<<" "<<diameter(root2)<<endl;

	findLCA(root, 7,9);

	preIter(root);
	X x;
	int q=10998977;
	Y *y1 = new Y(q);
	cout<<y1->a;

	cout<<endl;
	vi num{10,1,2,3,4,5,6,7,8,9,10};
	cout<<countDuplicate(num);

	return 0;
}