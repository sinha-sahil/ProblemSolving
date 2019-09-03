unordered_map<int, int> table;
 
TreeNode* generateTree(vector<int>& inorder, vector<int>& preorder, int& pindex, int start, int end){
    if(start>end || pindex > preorder.size()) return nullptr;
    TreeNode* root = new TreeNode(preorder[pindex++]);
    if(start == end){
        return root;
    }
    int partAt = table[root->val];
    root->left = generateTree(inorder, preorder, pindex, start, partAt-1);
    root->right = generateTree(inorder, preorder, pindex, partAt+1, end);
    return root;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    for(int i=0; i<B.size(); i++){
        table[B[i]] = i;
    }
    int pindex = 0;
    return generateTree(B, A, pindex,0, A.size()-1);
}