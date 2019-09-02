#include<iostream>
using namespace std;

int main(){
    int t; cin>>t;
    for(int i=0; i<t; i++){
        int n; cin>>n;
        int sumC=0;
        int sum=0;
        int common=15;
        int commThree= 3;
        int commFive=5;
        while(common<n){
            sumC+=common;
            common+=15;
        }
        while(commThree<n){
            sum+= commThree;
            commThree+=3;
        }
        while(commFive<n){
            sum+=commFive;
            commFive+=5;
        }
        
        cout<<(sum- sumC)<<endl;
    }
}
