//
// Created by Sahil_Sinha on 2019-07-14.
//

#include "Utils.h"
using namespace std;


int findSolution(vector<int> vi, int k){
    long long int modValue = 1000000007;
    long long int count = 0;

    for(long long int i= 0; i<vi.size(); i++){
        long long int area = vi[i] * vi[i];
        if(area < k) count++;
    }

    for(long long int i= 0; i<vi.size()-1; i++){
        long long int last = vi.size()-1;
        while(last > i){
            long long int area = vi[i] * vi[last];
            if(area >= k) last --;
            else if(area < k){
                count +=  2* (last- i) ;
                break;
            }
        }
    }
    long long int answer = count % modValue;
    return answer;

}

int main(){
    vectorInput vo;
    vector<int> vi = vo.vectorInp();
    int k; cin>>k;
    cout<<findSolution(vi,k);
}