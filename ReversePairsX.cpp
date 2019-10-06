#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& vi, int start, int mid, int end){
    vector<int> left(mid-start + 1);
    vector<int> right(end-mid);
    int index = 0;
    for(int i= start; i<= mid; i++) left[index++] = vi[i];
    index = 0;
    for(int i= mid+1; i<= end; i++) right[index++] = vi[i];
    int l = 0, r= 0;
    for(int k = start; k<=end; k++){
        if(r >= right.size() or (l < left.size() && left[l] < right[r])){
            vi[k] = left[l++];
        }
        else{
            vi[k]= right[r++];
        }
    }

}

int mergeCount(vector<int> &vi, int start, int end){
    if(start < end){
        int mid = start + (end-start)/2;
        int lCount = mergeCount(vi, start, mid);
        int rCount = mergeCount(vi, mid+1, end);
        int cCount = 0; int j = mid+1;
        for(int i= start; i<=mid; i++){
            while(j<= end && vi[i]> 2*vi[j])  j++;
            cCount += j - (mid+1);
        }
        merge(vi, start, mid, end);
        return (lCount + rCount + cCount);
    }
    return 0;
}

int getRevPCount(vector<int> &vi){
    return mergeCount(vi, 0, vi.size()-1);
}

int main(){
    vector<int> vi{1, 3, 2, 3, 1};
    cout<<getRevPCount(vi);
    cout<<endl;
    for(auto i: vi) cout<<i<<" ";
}