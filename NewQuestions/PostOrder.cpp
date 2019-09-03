#include<iostream>
using namespace std;


vector<int> postOrder(TreeNode* root){
	stack<TreeNode*> stk;
	vector<int> answer;
	stk.push(root);
	while(not stk.empty()){
		TreeNode* curr = stk.top();
		stk.pop();
		answer.push_back(curr->val);
		if(curr->left) stk.push(curr->left);
		if(curr->right) stk.push(curr->right);
	}
	reverse(begin(answer), end(answer));
	return answer;
}