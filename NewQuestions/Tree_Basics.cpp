#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int data): val(data), left(nullptr), right(nullptr){}
};

vector<vector<int>> zigZagLevelOrder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    bool zig = true;
    vector<vector<int>> answer;
    vector<int> temp;
    while(q.size()>1){
        TreeNode* curr = q.front();
        q.pop();
        if(curr){
            temp.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        else{
            if(zig){
                answer.push_back(temp);
            }
            else{
                reverse(begin(temp), end(temp));
                answer.push_back(temp);
            }
            zig = not zig;
            temp.clear();
            q.push(nullptr);
        }
    }
    if(not zig)
        reverse(begin(temp), end(temp));
    
    answer.push_back(temp);
    return answer;
}

int main(){
    TreeNode* root = nullptr;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    auto vec =  zigZagLevelOrder(root);
    for(auto i: vec){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}