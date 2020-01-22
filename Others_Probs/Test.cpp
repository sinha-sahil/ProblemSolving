//
// Created by Sahil_Sinha on 2019-07-13.
//

#include <iostream>
#include<vector>
#include<unordered_map>
//#include<bits/stdc++.h>
using namespace std;

// int findAns(vector<int> vi){
//     int N = vi.size();
//     int answer = -1;
//     int can1= INT_MIN; int con1= 0;
//     int can2= INT_MAX; int con2= 0;

//     for(auto i: vi){
//         if(i==can1) con1++;
//         else if(i==can2) con2++;
//         else if(con1==0) { con1=1; can1 = i;}
//         else if(con2==0) { can2=i; con2=1;}
//         else { con1--; con2--;}
//     }
//     int countA = 0;
//     int countB = 0;
//     for(auto i:vi) if(can1==i) countA++;
//     for(auto i:vi) if(can2==i) countB++;

//     if(countA  > N/3) return can1;
//     else if(countB > N/3) return can2;

//     return answer;
// }

int main()
{
    // vector<int> vi{1000727, 1000727, 1000641, 1000517, 1000212, 1000532, 1000727, 1001000, 1000254, 1000106, 1000405, 1000100, 1000736, 1000727, 1000727, 1000787, 1000105, 1000713, 1000727, 1000333, 1000069, 1000727, 1000877, 1000222, 1000727, 1000505, 1000641, 1000533, 1000727, 1000727, 1000727, 1000508, 1000475, 1000727, 1000573, 1000727, 1000618, 1000727, 1000309, 1000486, 1000792, 1000727, 1000727, 1000426, 1000547, 1000727, 1000972, 1000575, 1000303, 1000727, 1000533, 1000669, 1000489, 1000727, 1000329, 1000727, 1000050, 1000209, 1000109};
    // cout<<vi.size()<<endl;
    // unordered_map<int, int> table;
    // for(auto i: vi) table[i]++;
    // for(auto i: table) if(i.second > vi.size()/3) cout<<i.first<<endl;
    int a = INT_MAX;
    int b = INT_MAX;
    unsigned long long int product = INT_MAX*INT_MAX ;
    cout<<product<<endl;
    cout<<__INT_FAST32_MAX__<<endl;

    // cout<<findAns(vi);
}
