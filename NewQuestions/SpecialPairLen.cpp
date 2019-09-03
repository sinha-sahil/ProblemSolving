#include<iostream>
#include<unordered_map>
using namespace std;


int findSpecialPair(vector<int> vi){
    unordered_map<int, int> table;
    int min_len = INT_MAX;
    for(int i=0; i<vi.size(); i++){
        if(table.find(vi[i]) == table.end()){
            table[vi[i]] = i;
        }
        else{
            int cur_len = abs(i- table[vi[i]]);
            min_len = min(cur_len, min_len);
        }
    }
    return min_len;
}
