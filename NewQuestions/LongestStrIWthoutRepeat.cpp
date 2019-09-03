#include<iostream>
using namespace std;

int max_length(string input){
    unordered_map<char, int> table;
    vector<int> lenarr(input.size(), 1);
    int last_match = 0;
    for(int i=0; i<input.size(); i++){
        auto findex = table.find(vi[i]);
        if(findex == table.end()){
            int prev = (i == 0 ? 0 : lenarr[i-1]);
            lenarr[i] += prev + 1;
            table[vi[i]] = i;
        }
        else{
            int fprev = findex->second;
            if(last_match < fprev){
                last_match = fprev;
            }
            int cur_len = i - last_match;
            len_arr[i] = cur_len;
            table[vi[i]] = i;
        }
    }
    return *max_element(begin(lenarr), end(lenarr));

}