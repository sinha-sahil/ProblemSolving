//
// Created by Sahil_Sinha on 2019-07-09.
//

#include<iostream>
#include<vector>
using namespace std;

int findN3Max(vector<int> vi){
    int N = vi.size();
    int answer = -1;
    int can1= -1; int con1= 0;
    int can2= -1; int con2= 0;

    for(auto i: vi){
        if(con1==0){
            can1 = i;
            con1++;
        }
        else if(i==can1) con1++;
        else if(con2 == 0){
            can2 = i;
            con2++;
        }
        else if(i==can2) con2++;
        else {
            con1--;
            con2--;
        }
    }
    int countA = 0;
    int countB = 0;
    if(con1) for(auto i:vi) if(can1==i) countA++;
    if(con2) for(auto i:vi) if(can2==i) countB++;

    if(countA  >= N/3) return can1;
    else if(countB >= N/3) return can2;

    return answer;
}

int main(){
    int n; cin>>n;
    vector<int> vi(n);
    for(int i=0; i<n; i++) cin>>vi[i];

    cout<<findN3Max(vi);

}