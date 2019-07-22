//
// Created by Sahil_Sinha on 2019-07-13.
//
#include<iostream>
#include<vector>
#include "Utils.h"

using namespace std;

vector<vector<int>> pascalTrainge(int n){
    vector<vector<int>> pascal;
    if(n==0) return pascal;
    vector<int> temp{1};
    pascal.push_back(temp);
    int first = 0; int second = 1;

    for(int i=1; i<n; i++){
        first = 0; second =1;
        temp.clear();
        temp.push_back(1);
        int last = pascal[i-1].size();
        while(first<last and second < last ){
            temp.push_back(pascal[i-1][first] + pascal[i-1][second]);
            first++;
            second++;
        }
        temp.push_back(1);
        pascal.push_back(temp);

    }

    return pascal;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> answer = pascalTrainge(n);

    for(auto i: answer){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}