#include<iostream>
#include<cstdint>
using namespace std;

int main(){
    int t; cin>>t;
    for(int i=0; i<t; i++){
        uint64_t n; cin>>n;
        uint64_t sum=0;
        for(uint64_t k=3; k<n; k++){
            if(k%3==0 && k%5==0) sum+=k;
            else if(k%3==0) sum+=k;
            else if(k%5==0) sum+k;
        }
        cout<<sum<<endl;
    }
}
