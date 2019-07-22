//
// Created by Sahil_Sinha on 2019-07-14.
//

#include <iostream>
#include <vector>
#include "Utils.h"

using namespace std;

vector<int> findPair(vector<int> a, vector<int> b, int c){
    vector<int> answer;
    int s1= a.size();
    int s2=  b.size();
    int minDiff = INT_MAX;
    int x=0, y = s2-1;
    vector<vector<int>> poss;
    while(x<s1 and y>=0){
        int curDiff = abs(a[x]+ b[y] - c);

        if(curDiff <= minDiff){
            minDiff = curDiff;
            vector<int> temp{curDiff, x, y};
            poss.push_back(temp);
        }

        if(a[x]+b[y] > c) y--;
        else x++;

    }
    int fx = INT_MAX , fy = INT_MAX;
    for(auto i: poss){
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        if(i[0] == minDiff){
            if(i[1]< fx){
                fx = i[1];
                fy = i[2];
            }
            else if(i[1]== fx){
                if(i[2]<fy){
                    fx = i[1];
                    fy = i[2];
                }
            }
        }
    }
    answer.push_back(a[fx]);
    answer.push_back(b[fy]);
    return answer;
}


//printClosest(int ar1[], int ar2[], int m, int n, int x)
//{
//    // Initialize the diff between pair sum and x.
//    int diff = INT_MAX;
//
//    // res_l and res_r are result indexes from ar1[] and ar2[]
//    // respectively
//    int res_l, res_r;
//
//    // Start from left side of ar1[] and right side of ar2[]
//    int l = 0, r = n-1;
//    while (l<m && r>=0)
//    {
//        // If this pair is closer to x than the previously
//        // found closest, then update res_l, res_r and diff
//        if (abs(ar1[l] + ar2[r] - x) < diff)
//        {
//            res_l = l;
//            res_r = r;
//            diff = abs(ar1[l] + ar2[r] - x);
//        }
//
//        // If sum of this pair is more than x, move to smaller
//        // side
//        if (ar1[l] + ar2[r] > x)
//            r--;
//        else  // move to the greater side
//            l++;
//    }
//
//    // Print the result
//    cout << "The closest pair is [" << ar1[res_l] << ", "
//         << ar2[res_r] << "] \n";
//}

int main(){
    vectorInput vo;
    vector<int> a=vo.vectorInp();
    vector<int> b=vo.vectorInp();
    int c; cin>>c;
    vector<int> vi= findPair(a, b,c);
    cout<<vi[0]<<" "<<vi[1];
}