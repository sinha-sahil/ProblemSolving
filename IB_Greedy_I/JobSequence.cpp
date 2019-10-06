#include<iostream>
#include<vector>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int>p2){
    return p1.second < p2.second;
}

int solve(vector<int> &A, vector<int> &B) {
    vector<pair<int, int>> vi;
    int maxDays = 0;
    for(int i=0; i<A.size(); i++){
        maxDays = max(maxDays, A[i]);
        vi.push_back(make_pair(A[i], B[i]));
    }

    sort(begin(vi), end(vi), compare);

    vector<int> answer(maxDays, 0);
    int totalProfit = 0;

    for(auto i : vi){
        int st = i.first;
        while(st>=0 && answer[st]!=0) st--;
        if(st<0) continue;
        else {
            answer[st] = i.second;
            totalProfit += i.second;
        }
    }
    return totalProfit;

}
