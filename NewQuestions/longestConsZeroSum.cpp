#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> fingLongestConsecutiveZero(vector<int> vi){
    unordered_map<int, int> table;
    vector<long long int> csum(vi.size(), 0);
    csum[0]= vi[0];
    for(int i=1; i<vi.size(); i++){
        csum[i] = csum[i-1] + vi[i];
    }
    int max_len = 0;
    int start = -1; int end = -1;
    for(int i= 0; i<csum.size(); i++){
        if(table.find(csum[i]) == table.end()){
            table[csum[i]] = i;
        }
        else{
            if(csum[i] == 0){
                int cur_len = i+1;
                if(cur_len > max_len){
                    start = 0;
                    end = i;
                    max_len = cur_len;
                }
            }
            else {
                int cur_len = i-table[csum[i]];
                if(cur_len > max_len){
                    start = table[csum[i]] + 1;
                    end = i;
                    max_len = cur_len;
                }
            }
        }
    }
    if(csum[csum.size()-1] + csum[0] == 0){
        start = 0;
        end = csum.size()-1;
        max_len = csum.size();
    }
    vector<int> answer;
    answer.push_back(start); answer.push_back(end);
    return answer;
}

int main(){
    return 0;
}