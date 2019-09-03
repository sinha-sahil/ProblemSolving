#include<iostream>
#include<vector>
using namespace std;

int getTrappedWater(vector<int> arr){
    vector<int> larr(arr.size(), 0);
    vector<int> rarr(arr.size(), 0);
    int cMax = 0;
    for(int i = arr.size()-1; i>= 0; i--){
        if(cMax < arr[i]){
            cMax = arr[i];
        }
        rarr[i] = cMax;
    }
    rarr[arr.size()-1] = 0;
    cMax  = 0;
    for(int i = 0; i<arr.size(); i++){
        if(cMax <arr[i]){
            cMax = arr[i];
        }
        larr[i]= cMax;
    }
    larr[0] = 0;

    int storedvalue = 0;

    for(int i= 0; i<arr.size(); i++){
        int cmin = min(larr[i], rarr[i]);
        int value = cmin- arr[i];
        if(value >0){
            storedvalue += value;
        }
    }
    return storedvalue;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vi(n, 0);
        for(int i=0; i<n; i++) cin>>vi[i];
        cout<<getTrappedWater(vi)<<"\n";
    }
}