bool getPath(TreeNode* root, vector<int>& path, int key){
    if(root == nullptr) return false;
    path.push_back(root->val);
    if(root->val == key) return true;
    if(getPath(root->left, path, key) || getPath(root->right, path, key)) return true;
    path.pop_back();
    return false;
}

int Solution::lca(TreeNode* root, int B, int C) {
    vector<int> path1;
    vector<int> path2;
    bool pone = getPath(root, path1, B);
    bool ptwo = getPath(root, path2, C);
    if(pone && ptwo){
        int common;
        int min_size = min(path1.size(), path2.size());
        int index = min_size-1;
        while(index>= 0){
            if(path1[index] == path2[index]){
                common = path1[index];
                return common;
            }
            index--;
        }
    }
    return -1;
}