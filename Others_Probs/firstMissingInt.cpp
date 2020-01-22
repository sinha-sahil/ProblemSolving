//
// Created by Sahil_Sinha on 2019-07-09.
//

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> vi(n);
    for(int i=0; i<n; i++) cin>>vi[i];
    cout<<findMissing(vi);
}