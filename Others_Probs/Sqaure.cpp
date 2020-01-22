#include<iostream>
using namespace std;

int findSqrt(int n){
    int high = n;
    int low = 0;

    while(low<= high){
        int mid = low  + (high -low)/2;
        int value = mid*mid ;

        if(value == n) return mid;
        else if(value < n)  low = mid+1;
        else if(value > n)  high = mid-1;
    }

    return low;
}

int main(){
    int n;
    cin>>n;
    cout<<findSqrt(n);
}