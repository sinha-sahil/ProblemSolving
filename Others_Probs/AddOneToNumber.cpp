//
// Created by Sahil_Sinha on 2019-07-09.
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> addOne(vector<int> vi){
    vector<int> result;
    if(vi.size()==0) return result;
    int firstIndex = -1;
    for(int i = 0; i<vi.size(); i++){
        if(vi[i]>0) {
            firstIndex = i;
            break;
        }
    }
    int carry = 1;
    int index = vi.size()-1;
    while(carry && index >=0){
       int newValue = vi[index] + carry;
       carry = 0;
       if(newValue > 9) {
           carry = 1;
           newValue -= 10;
       }
       result.push_back(newValue);
       index--;
    }
    while(index>=0) {
        if(firstIndex != -1 and index >=firstIndex)
            result.push_back(vi[index]);
        index--;
    }
    if(carry) result.push_back(1);
    reverse(begin(result), end(result));
    return result;
}

int main(){
    int n; cin>>n;
    vector<int> vi(n);
    for(int i=0; i<n; i++) cin>>vi[i];
    vector<int> temp;
    temp = addOne(vi);
    for(auto i: temp) cout<<i;
}