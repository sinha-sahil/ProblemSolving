#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


vector<vector<int>> sol(vector<string> array){
    unordered_map<string, vector<int>> table;
    vector<vector<int>> answer;
    for(int i=0; i<array.size(); i++){
        string curr = array[i];
        sort(begin(curr), end(curr));
        auto findex = table.find(curr);
        if(findex == table.end()){
            vector<int> vi;
            vi.push_back(i);
            table[curr] = vi;
        }
        else{
            findex->second.push_back(i);
        }
    }
    for(auto i: table){
        answer.push_back(i.second);
    }
    return answer;
}

int main(){
    return 0;
}