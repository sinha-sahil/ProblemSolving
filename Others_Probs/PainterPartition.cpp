#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int personsReq(vector<int>& vi, int t){
    int count = 1;
    int curr = 0;
    for(auto i: vi){
        curr += i;
        if(curr >t) {
            curr = i;
            count++;
        }
    }
    return count;
}

int minimumTime(vector<int> vi, int k, int a){
    int high = 0;
    for(auto i: vi) high+= i;
    int low = *max_element(begin(vi), end(vi));
    while(low < high){
        int mid = low + (high-low)/2;
        int kdash= personsReq(vi,mid);
        if(kdash <=k){ 
            high = mid;
        }
        else if(kdash >k) low = mid+1; 
    }
    return low*a;
}

int main(){
    int n; cin>>n;
    int k; cin>>k;
    int a; cin>>a;
    vector<int> vi(n);
    for(int i=0; i<n; i++) cin>>vi[i];
    cout<<minimumTime(vi, k, a);
}