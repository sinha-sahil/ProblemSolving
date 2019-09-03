#include<iostream>
#include<vector>
using namespace std;

int bin_search(vector<int> vi, int key){
    int high = vi.size()-1;
    int low = 0;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(vi[mid]== key){
            return mid;
        }
        else if(vi[mid]< key) low = mid+1;
        else if(vi[mid]>key) high = mid-1;
    }
    return -1;
}

vector<int> solve(vector<int> vi){
    unordered_map<int, vector<int>> table;

    for(int i=0; i<vi.size(); i++){
        auto findex = table.find(vi[i]);
        if(findex == table.end()){
            vector<int> temp;
            temp.push_back(i);
            table[vi[i]] = temp;
        }
        else{
            findex->second.push_back(i);
        }
    }

    vector<int> answer;

    for(int i=0; i<vi.size(); i++){
        int cIndex = bin_search(table[vi[i]], i);
        int x = table[vi[i]].size() - cIndex -1;
        int y = cIndex;
        answer.push_back(x-y);
    }
    return answer;

}