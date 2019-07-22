//
// Created by Sahil_Sinha on 2019-07-11.
//

#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;


int findMinAbsDiff(vector<int> a, vector<int>  b , vector<int>  c){
    int minDiff= INT_MAX;
    int p1, p2, p3;
    p1=p2=p3=0;
    int n1= a.size();
    int n2= b.size();
    int n3= c.size();

    int xa = a[p1];
    int xb = b[p2];
    int xc = c[p3];

    while(p1<n1 or p2<n2 or p3<n3){
        if(p1<n1) xa = a[p1];
        if(p2<n2) xb = b[p2];
        if(p3<n3) xc = c[p3];
        int minValue = min(xa, min(xb, xc));
        int maxValue = max(xa, max(xb, xc));
        minDiff = min(minDiff, maxValue-minValue);
        if( minValue == a[p1]){
            p1++;
        }
        else if(minValue == b[p2]){
            p2++;
        }
        else if(minValue == c[p3]){ p3++;
        }

    }
    return minDiff;
}


int main(){
    vectorInput vo;
    vector<int> vi = vo.vectorInp();
    vector<int> vj = vo.vectorInp();
    vector<int> vk = vo.vectorInp();

    cout<<findMinAbsDiff(vi, vj, vk);
}