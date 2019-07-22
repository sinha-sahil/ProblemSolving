#include<iostream>
#include<vector>
using namespace std;

int findMinCandy(vector<int> vi){
    int n= vi.size();
    vector<int> candy(n, 1);
    for(int i=1; i<n; i++){
        if(vi[i]> vi[i-1]) candy[i]= candy[i-1]+1;
    }
    for(int i= n-2; i>=0; i--){
        if(vi[i]> vi[i+1]) candy[i] = max(candy[i], candy[i+1]);
    }
    int sum_value=0;
    for(auto i: candy) sum_value+=i;
    return sum_value;
}

int main(){
    int n;
    cin>>n;
    vector<int> vi(n);
    for(int i=0; i<n; i++) cin>>vi[i];
    cout<<findMinCandy(vi);
}