#include<iostream>
using namespace std;


vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>> answer;
    if(A == nullptr) return answer;
    map<int, vector<int>> table;
    queue<pair<int, TreeNode*>> q;
    q.push(make_pair(0, A));
    while(q.size()){
        pair<int, TreeNode*> curr = q.front();
        q.pop();
        if(table.find(curr.first) == table.end()){
            vector<int> vi;
            vi.push_back(curr.second->val);
            table[curr.first]= vi;
        }
        else{
            table[curr.first].push_back(curr.second->val);
        }
        if(curr.second->left) q.push(make_pair(curr.first-1, curr.second->left));
        if(curr.second->right) q.push(make_pair(curr.first+1, curr.second->right));
    }
    
    
    for(auto i: table){
        answer.push_back(i.second);
    }
    return answer;
}