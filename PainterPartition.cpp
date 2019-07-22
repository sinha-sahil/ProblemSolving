#include<iostream>
#include<vector>

using namespace std;

int getPersons(vector<int> vi, int k){
    int count =0;
    int value = 0;
    for(auto i: vi){
        if(value+i < k) continue;
        else { count++; value = 0;}
    }
    return count;
}

int findMinTime(vector<int> vi, int k){
    int lowerLimit = *min_element(begin(vi), end(vi));
    int higherLimit = *max_element(begin(vi), end(vi));

    int answer = INT_MAX;
    int mid;
    while(lowerLimit <= higherLimit){
        mid = lowerLimit +  (higherLimit - lowerLimit)/2;
        int kdash = getPersons(vi, mid);
        if(kdash <= k){
            answer = min(kdash, answer);
        }
        else if(kdash > k){
            lowerLimit = mid+1;
        }
        else higherLimit = mid-1;
    }
    return answer;
}

int main(){
    // int n; cin>>n;
    int k; cin>>k;
    int l; cin>>l;
    vector<int> vi(l);
    for(int i=0; i<l; i++) cin>>vi[i];
    cout<<findMinTime(vi, k);
}