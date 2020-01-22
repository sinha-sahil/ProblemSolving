#include "bits/stdc++.h"
using namespace std;

vector<long long int> table;

string solve(int n) {
    queue<long long int> q;
    q.push(1);
    q.push(2);
    long long int popCount = 0;
    long long int front = 1;
    if(table.size() < n){
        table.clear();
        while(popCount != n){
            front = q.front();
            table.push_back(front);
            q.pop();
            popCount++;
            long long int fNum = front*10 + 1;
            long long int sNum = front*10 + 2;
            q.push(fNum);
            q.push(sNum);
        }
    }
    else front = table[n-1];

    string answer;
    answer = to_string(front);
    string fans = answer;
    reverse(begin(answer), end(answer));
    fans += answer;
    return fans;
}
