//
// Created by Sahil_Sinha on 2019-07-09.
//

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> vi){
    cout<<"\nVector::";
    for(auto i: vi) cout<<i<<" ";
    cout<<"\n";
}

int rearrange(vector<int>& vi){
    int swapIndex = 0;
    for(int i=0; i<vi.size(); i++) {
        if (vi[i] < 0) {
            swap(vi[i], vi[swapIndex]);
            swapIndex++;
        }
    }
    return swapIndex;
}

int findFirst(vector<int> vi){
   int swapIndex = rearrange(vi);
   if(swapIndex == vi.size()) return 1;

   int n= vi.size();
   for(int i= swapIndex; i<n; i++){
       int currValue = abs(vi[i]);
       int actualIndex = currValue-1 + swapIndex;
       if(actualIndex >n ) continue;
       else if(actualIndex < n){
           vi[actualIndex]= -vi[actualIndex];
       }
   }
   for(int i=swapIndex; i<n; i++){
       if(vi[i]<0) continue;
       else {
           int index = i-swapIndex +1;
           return index;
       }
   }
   int other = n- swapIndex +1;
   return other;
}

int main(){
    int n; cin>>n;
    vector<int> vi(n);
    for(int i=0; i<n; i++) cin>>vi[i];
    cout<<findFirst(vi);
}