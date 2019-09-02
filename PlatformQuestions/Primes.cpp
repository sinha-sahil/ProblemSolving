#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> vi;

int binarySearch(int number){ 
    int low=0;
    int high=vi.size()-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(number== vi[mid]){
            return mid;
        } else{
            if(number< vi[mid]){
                high= mid-1;
            } else if(number> vi[mid]){
                low= mid+1;
            }
        }
    }
   return -1; 
} 

bool primeTest(int n){
    if(n==0 || n==1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}

void generatePrime(int limit){
    int start= vi[vi.size()-1];
    for(int i= start+1; i<= limit; i++){
        if(primeTest(i)){
            vi.push_back(i);
        }
    }
}

int main() {
    vi.push_back(2);
    long long int ranges;
    cin>>ranges;
    for(int i=0; i< ranges; i++){
        long long int count=0;
        long long int start;
        long long int end;
        cin>>start>>end;
        while(!primeTest(start)) start++;
        while(!primeTest(end)) end--;
        long long int endFind= binarySearch(end);
        if(endFind!=-1){
            long long int findIndex= binarySearch(start);
            long long int endIndex= binarySearch(end);
            count= endIndex+1- findIndex;
        } else{
            generatePrime(end);
            long long int findIndex= binarySearch(start);
            long long int endIndex= binarySearch(end);
            count= endIndex+1- findIndex;
        }
        cout<<count<<endl;
    }
    return 0;
}

