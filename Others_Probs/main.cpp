#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b){
    a = a+b;
    b = a-b;
    a = a-b;
}

void revVec(vector<int>& vi, int start, int end){
    if(vi.size()==0) return;
    while(start<= end){
        swap(vi[start], vi[end]);
        start++;
        end--;
    }
}

void nextPermutation(vector<int>& nums){
    int current= nums.size()-1;
    int changeIndex = -1;
    for(int i= current; i>=0; i--){
        if(nums[i]<nums[i+1]){
            changeIndex = i;
            break;
        }
    }
    if (changeIndex == -1){
        revVec(nums, 0, current);
        return;
    }
    int valueDiff= INT_MAX;
    int swapIndex = -1;
    for(int i= changeIndex+1; i<nums.size(); i++){
        int valx = nums[i]- nums[changeIndex];
        if(valx < valueDiff){
            valueDiff= valx;
            swapIndex = i;
        }
    }
    swap(nums[changeIndex], nums[swapIndex]);
    revVec(nums, changeIndex+1, current);

}


int main() {
    vector<int> nums{1,2,3,4};
    nextPermutation(nums);
    for(auto i: nums) cout<<i<<" ";
    return 0;
}