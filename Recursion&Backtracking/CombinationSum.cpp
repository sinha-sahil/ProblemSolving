// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. Each number in C may only be used once in the combination.

// Example : Given candidate set 10,1,2,7,6,1,5 and target 8, A solution set is:
// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void generateSets(vector<int>& arr, set<vector<int>>& answer, vector<int> cArr, int cSum, int currentIndex){
    if(cSum == 0)
        answer.insert(cArr);
    else if (cSum < 0) 
        return;
    while (currentIndex < arr.size() && cSum - arr[currentIndex]>=0){
        int xSum = cSum - arr[currentIndex];
        cArr.push_back(arr[currentIndex]);
        generateSets(arr, answer, cArr, xSum, currentIndex+1);
        cArr.pop_back();
        currentIndex++;
    }
}


int main(){
    vector arr = {10,1,2,7,6,1,5};
    sort(begin(arr), end(arr));
    // arr.erase(unique(begin(arr), end(arr)), arr.end());
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    set<vector<int>> answer;
    vector<int> cArr;
    generateSets(arr, answer, cArr, 8, 0);
    for(auto i: answer){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}