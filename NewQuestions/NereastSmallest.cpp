#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> getNearest(vector<int> arr){
    stack<int> stk;
    vector<int> answer;

    for(int i=0; i<arr.size(); i++){
        if(stk.empty()){
            answer.push_back(-1);
        }
        else{
            while(not stk.empty() and stk.top()> arr[i]){
                stk.pop();
            }
            if(stk.empty()){
                answer.push_back(-1);
            }
            else{
                answer.push_back(stk.top());
                stk.push(arr[i]);
            }
        }
    }
    return answer;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> vi(n, 0);
        for(int i=0; i<n; i++) cin>>vi[i];
        vector<int> ans = getNearest(vi);
        for(auto i: ans) cout<<i<<" ";
        cout<<endl;
    }
}