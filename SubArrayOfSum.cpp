//
// Created by Sahil_Sinha on 2019-07-10.
//

#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

vector<int> findArray(vector<int> vi, int k){
    vector<int> answer;
    int n = vi.size();
    int first= 0;
    int second = 0;

    int cur_sum = vi[first];

    while(second< n and first<=second){
        if(cur_sum == k){
            answer.push_back(first+1);
            if(second!=0) answer.push_back(second);
            else answer.push_back(1);
            return answer;
        }
        else if(cur_sum < k){
            if(second !=0) cur_sum += vi[second];
            second++;
        }
        else if(cur_sum > k) {
            cur_sum -= vi[first];
            first++;
        }
    }
    if(cur_sum > k){
        while(cur_sum >k and first < n) {
            cur_sum -= vi[first];
            first++;
        }
    }
    if(cur_sum == k) {
        answer.push_back(first+1);
        if(second!=0) answer.push_back(second);
        else answer.push_back(1);
        return answer;
    }
    answer.push_back(-1);
    return answer;
}

int main(){
    vectorInput vo;
    vector<int> vi = vo.vectorInp();
    int k;
    cin>>k;
    vector<int> answer = findArray(vi,k);
    cout<<answer[0]<<" "<<answer[1];

}