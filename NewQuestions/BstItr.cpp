#include<iostream>
using namespace std;


void inorder(TreeNode* root){
	stack<TreeNode*> stk;
	TreeNode* curr= root;
	while(curr!= nullptr || not stk.empty()){
		while(curr!= nullptr){
			stk.push(curr);
			curr = curr->left;
		}
		curr = stk.top();
		cout<<curr->val<<" ";
		curr = curr->right;
	}
}

stack<TreeNode*> stk;

void fillStack(TreeNode* root){
	while(root!= nullptr){
		stk.push(root);
		root = root->left;
	}
}

BSTIterator::BSTIterator(TreeNode *root) {
	stk.clear();
	fillStack(root);
}

bool BSTIterator::hasNext() {
	return not stk.empty();
}

int BSTIterator::next() {
	TreeNode* curr= stk.top();
	stk.pop();
	if(curr->right) fillStack(curr->right);
	return curr->val;
}