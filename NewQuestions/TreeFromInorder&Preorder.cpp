#include<iostream>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left, *right;
	TreeNode(int dat): val(dat), left(nullptr), right(nullptr){}
};

int findPos(vector<int> vi, int start, int end, int key){
	for(int i=start; i<= end; i++){
		if(vi[i] == key) return i;
	}
	return -1;
}

TreeNode* generateTree(vector<int> inorder, vector<int> preorder, int pindex, int start, int end){
	TreeNode* root = new TreeNode(preorder[pindex++]);
	if(start == end){
		return root;
	}
	int partAt = findPos(inorder, start, end, root->val);
	root->left = generateTree(inorder, preorder, pindex, start, partAt-1);
	root->right = generateTree(inorder, preorder, pindex, partAt+1, end);
	return root;
}

