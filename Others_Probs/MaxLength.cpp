#include<iostream>
#include<vector>
using namespace std;

int toNumber(char i){
    return static_cast<int>(i)-48;
}

void printVector(vector<int> vi){
    cout<<endl<<"Print Vector";
    for(auto i: vi) cout<<i<<" ";
    cout<<endl;
}

int findMaxLength(string num){
    int n = num.size();
    vector<int> prefix(n, 0);
    vector<int> suffix(n, 0);

    int oneCount = 0;

    for(int i=0, j= n-1; i<n, j>=0; i++, j--){
        int v1 = toNumber(num[i]);
        int v2 = toNumber(num[j]);

        if(v1 == 1){
            if(i!=0) prefix[i] = prefix[i-1]+1;
            else prefix[i] = 1;
            oneCount++;
        }
        if(v2 == 1){
            if(j !=  n-1) suffix[j] = suffix[j+1]+1;
            else suffix[j] = 1;
        }
    }

    int maxCount = 0;

    for(int i=0; i<n; i++){
        int x= toNumber(num[i]);
        if(x == 0){
            int pValue = i == 0 ? 0 : prefix[i-1];
            int sValue = i == n-1 ? 0:  suffix[i+1];
            int pushValue = pValue + sValue;
            if(pushValue < oneCount) pushValue+=1;
            maxCount = max(pushValue, maxCount);
        }

    }
    return maxCount;
}

int main(){
    string num;
    cin>>num;
    cout<<findMaxLength(num);
}