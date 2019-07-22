//
// Created by Sahil_Sinha on 2019-07-13.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "Utils.h"

using namespace std;

int findCounts(vector<int> vi){
    sort(begin(vi), end(vi));
    int count =0;
    int n= vi.size();

    for(int i=0; i<n-2; i++){
        int k = i+2;
        for(int j=i+1; j<n; j++){
            while(k<n and vi[i]+vi[j] > vi[k]) ++k;
            if(k>j)
            count += k-j-1;
        }
    }
    return count;
}

int findEffCount(vector<int> vi){
    sort(begin(vi), end(vi));
    int count = 0;
    int n= vi.size();
    for(int i= n-1; i>=1; i--){
        int l = 0; int r= i-1;
        while(l<r){
            if(vi[l]+vi[r]> vi[i]){
                count += r-l;
                r--;
            }
            else l++;
        }
    }
    return count;
}

int main(){
    vectorInput vo;
    vector<int> vi = vo.vectorInp();
    cout<<findEffCount(vi);
}

//10, 21, 22, 100, 101, 200, 300