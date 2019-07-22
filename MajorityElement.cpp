//
// Created by Sahil_Sinha on 2019-07-09.
//

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int findMajority(vector<int> vi){
    if(vi.size() ==  0) return -1;
    int assumedMajor = vi[0];
    int count = 1;

    for(int i= 1; i< vi.size(); i++){
        if(vi[i] == assumedMajor) count++;
        else if(vi[i] != assumedMajor){
            if(count == 0){
                assumedMajor = vi[i];
                count++;
            }
            else if(count>0){
                count--;
            }
        }
    }

    if(count <1) return -1;
    int rcount = 0;
   for(auto i: vi) if(i == assumedMajor) rcount++;
   int req = floor(vi.size()/2.0);
   if(rcount >= req) return assumedMajor;
   return -1;

}

int main(){
    int n;
    cin>>n;
    vector<int> vi(n);
    for(int i=0; i<n; i++) cin>>vi[i];
    cout<<findMajority(vi);
}