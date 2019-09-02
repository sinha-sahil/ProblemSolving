#include<iostream>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        long double d, a, m, b, x;
        cin>>d>>a>>m>>b>>x;
        long double amount=d;
        lond double elapsed;
        lond double newN= x/(a*m +b);
        elapsed= newN* (m+1);
        cout<<static_cast<int>(elapsed)<<endl;
    }
    return 0;
}
