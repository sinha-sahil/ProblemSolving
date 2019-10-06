#include<iostream>
#include<vector>
using namespace std;


vector<int> Solution::solve(vector<int> &A, string str) {
    vector<pair<int,int>> vi;
    
    for(int i=0; i<A.size(); i++)
        vi.push_back(make_pair(A[i], i));
        
    sort(begin(vi), end(vi), [](pair<int,int> p1, pair<int, int> p2) {
         return (p1.first < p2.first);
    });
    
    stack<int> stk;

    int start = 0; int end = vi.size()-1;
    
    vector<int> answer;
    
    for(int i=0; i<str.size(); i++){
        if(str[i] == '0'){
            stk.push_back(start);
            answer.push_back(vi[start].second + 1);
            start++;
        }
        else{
            if(stk.empty()){
                answer.push_back(vi[end].second + 1);
                end--;
            }
            else{
                answer.push_back(vi[stk.top()].second + 1);
                stk.pop();
            }
        }
    }
    return answer;
}
