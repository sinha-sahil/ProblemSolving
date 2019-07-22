//
// Created by Sahil_Sinha on 2019-07-13.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> findNthRow(int n){
    vector<int> answer;
    answer.push_back(1);

    for(int i=1; i<=n; i++){
        double j = i-1;
        double lastElement = answer[j];
        double multiplier = n-j;
        multiplier /= i;
        double element = lastElement * multiplier;
        answer.push_back(element);
    }

    return answer;
}

int main(){
    int n;
    cin>>n;
    vector<int> vi = findNthRow(n);
    for(auto i: vi) cout<<i<<" ";
}

