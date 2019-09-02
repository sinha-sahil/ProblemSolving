#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left, *right;
	Node(int val){
		data= val;
		left= nullptr;
		right = nullptr;
	}
};

void insert(Node* &root, int data){
	if(root== nullptr){
		root= new Node(data);
		return;
	}
	if(data<root->data) insert(root->left, data);
	else insert(root->right, data);
}

void inorder(Node* root){
	if(root== nullptr) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

//pair<Node*, Node*> findkey(Node* root, Node* prev, int data){
//	if(root== nullptr) return make_pair(null[p]);
//	if(root->data == data) return make_pair(root, prev);
//	else if(root->data< data) findkey(root->right, root, data);
//	else if(root->data > data) findkey(root->left, root, data);
//}

void deleteKey(Node* root, int key){
	
}

void inorder_vec(Node* root, vector<int>& vi){
	if(root==nullptr) return;
	inorder_vec(root->left, vi);
	vi.push_back(root->data);
	inorder_vec(root->right);
}

int count_swaps_to_binary(Node* root){
	vector<int> vi;
	int count=0;
	inorder(root, vi);
	for(int i=0; i< vi.size(); i++){
		for(int j= 0; j<vi.size()-i-1; j++){
			if(vi[j]> vi[j+1])
			count++;
		}
	}
	return count;
}

Node* lca(Node* root, int v1, int v2){
	if(root==nullptr) return nullptr;
    int t1= min(v1,v2);
    int t2= max(v1, v2);
    while(not(root->data >= t1) or not(root->data <= t2)){
        if(root->data > t2 ) root= root->left;
        else root= root->right;
    }
    return root;
}

int main(){
	Node* root= nullptr;
	insert(root, 10);
	insert(root, 8);
	insert(root, 20);
	insert(root, 7);
	insert(root, 9);
	insert(root, 11);
	insert(root, 21);
	cout<<"Inorder: ";
	inorder(root);
}
