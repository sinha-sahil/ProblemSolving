#include<iostream>
using namespace std;


unordered_map<int, int> table;

TreeNode* generateTree(vector<int>& inorder, vector<int>& postorder, int pindex, int start, int end){
	if(start> end) return nullptr;
	TreeNode* root = new TreeNode(postorder[pindex--]);
	if(start == end) retrun root;
	int pIndex = table[root->val];
	root->left = generateTree(inorder, postorder, pindex, start, pIndex-1);
	root->right = generateTree(inorder, postorder, pindex, pIndex+1, end);
	return root;
}