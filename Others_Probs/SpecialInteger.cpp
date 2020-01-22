#include<iostream>
#include<algorithm>
#include "Utils.h"
using namespace std;

int findK(vector<int> vi, int b){
    sort(begin(vi), end(vi));
    vector<int> sumValues;
    int last = 0;
    for(auto i: vi){
        int curValue = last + i;
        sumValues.push_back(curValue);
        last = sumValues[sumValues.size()-1];
    }
  
    int vs = vi.size();
    int low = 0;
    int high = vs-1;
    int k = 0;

    vectorUtil vo;
    vo.print(vi);
    vo.print(sumValues);

    while(low<= high){
        int mid = low + (high - low)/2;
        int p1 = vs - mid;
        int rangeSum;
        if(p1 == 0) rangeSum = sumValues[vs-1];
        else rangeSum = sumValues[vs-1]- sumValues[p1-1];
        
        cout<<"mid: "<<mid<<" k: "<<k<<" sum: "<<rangeSum<<endl;

        if(rangeSum <=b){
            k = max(k, mid);
            low = mid+1;
        }
        else if(rangeSum > b ){
            // cout<<"Came here once";
            high = mid-1;
        }
    }
    return k;
}

int main(){
    vectorUtil vo;
    vector<int> vi {2, 24, 38, 25, 35, 33, 43, 12, 49, 35, 45, 47, 5, 33};
    // = vo.vectorInp();
    int b; cin>>b;
    cout<<findK(vi, b);
}