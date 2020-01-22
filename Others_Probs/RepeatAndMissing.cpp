//
// Created by Sahil_Sinha on 2019-07-09.
//

#include<iostream>
#include<vector>
using namespace std;

vector<int> findMissing(vector<int> vi){
    vector<int> answer;
    int n= vi.size();

    int xorValue= 0;
    for(auto i: vi) xorValue = xorValue xor i;

    for(int i=1; i<=n; i++) xorValue = xorValue xor i;

    int setBit = xorValue & ~(xorValue -1);

    int part1 = 0;
    int part2 = 0;

    for(int i=0; i<n; i++){
        if(vi[i] & setBit) part1 = part1 xor vi[i];
        else part2 = part2 xor vi[i];
    }

    for(int i=1; i<=n; i++){
        if(i & setBit) part1 = part1 xor i;
        else part2= part2 xor i;
    }

    int countValue = 0;
    for(auto i: vi) if (i == part1) countValue++;

    if(countValue){ answer.push_back(part1); answer.push_back(part2);}
    else {
        answer.push_back(part2);
        answer.push_back(part1);
    }
    return answer;
}

int main(){
    int n; cin>>n;
    vector<int> vi(n);
    for(int i=0; i<n; i++) cin>>vi[i];
    vector<int> ans
}