#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int getMaxHeight(vector<int> vi){
    stack<int> stk;
    int maxArea = 0;
    int i;
    while(i<vi.size()){
        if(stk.empty() or vi[stk.top()] <= vi[i])
            stk.push(i++);
        
        else{
            int ctop= stk.top();
            stk.pop();
            int currArea = vi[ctop] * (stk.empty()? i: i-stk.top()-1);
            cout<<currArea<<endl;
            maxArea = max(currArea, maxArea);
        }
    }

    while(not stk.empty()){
        int ctop = stk.top();
        stk.pop();
        int currArea = vi[ctop] * (stk.empty()? i: i-stk.top()-1);
        cout<<currArea<<endl;
        maxArea = max(currArea, maxArea);
    }

    return maxArea;
}


int main(){
    int n;
    cin>>n;
    vector<int> vi(n, 0);
    for(int i=0; i<n; i++) cin>>vi[i];
    cout<<getMaxHeight(vi);
}

// 6 2 5 4 5 1 6