#include "bits/stdc++.h"

using namespace std;

vector<int> sortStack(vector<int>& vi){
    stack<int> stk1;
    for(auto i: vi) stk.push(i);
    stack<int> stk2;
    
    while(stk1.size()){
        if(stk2.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        else{
            while(stk1.size() && stk2.size() && stk2.top() > stk1.top()){
                stk2.push(stk1.top());
                stk1.pop();
            }
            int x = stk1.size() ? stk1.top() : -1;

            if(x!= -1){
                stk1.pop();
                while(stk2.size() && stk2.top() < x){
                    stk1.push(stk2.top());
                    stk2.pop();
                }
                stk2.push(x);
                x = -1;
            }
            else break;
        }
    }
    vector<int> answer;
    while(stk2.size()) {
        answer.push_back(stk2.top());
        stk2.pop();
    }

    return answer;
   
}

int main(){
    cout<<"hey";
}