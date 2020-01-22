#include<iostream>
#include<vector>
using namespace std;

void swap(int& a, int& b){
    a= a+b;
    b= a-b;
    a= a-b;
}

void revVec(vector<int>& vi, int start, int end){
    if(start== end) return;
    while(start<end){
        swap(vi[start], vi[end]);
        start++;
        end--;
    }
}

void findNextPermutation(vector<int>& vi){
    int n= vi.size();
    if(n==0 or n==1) return;

    bool increase = true;
    int index = -1;

    for(int i=n-2; i>=0; i--){
        if(vi[i] < vi[i+1]){
            index= i;
            increase = false;
            break;
        }
    }

    if(increase){
        revVec(vi, 0, vi.size()-1);
        return;
    }
    else {
        int diff= INT_MAX;
        int spIndex = 0;
        for(int i=index+1; i<n; i++){
            int cdiff = vi[i] - vi[index];
            if(cdiff < diff){
                cdiff = diff;
                spIndex = i;
            }
        }
        swap(vi[spIndex], vi[index]);
        revVec(vi, index+1, n-1);
        return;
    }


}

int main(){
    int n;
    cin>>n;
    vector<int> vi(n);
    for(int i=0; i<n; i++) cin>>vi[i];

    findNextPermutation(vi);
    //revVec(vi, 0, vi.size()-1);
    for(auto i: vi) cout<<i<<" ";
}