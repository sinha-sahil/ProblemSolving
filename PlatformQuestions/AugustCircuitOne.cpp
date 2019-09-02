#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int d, a, m, b, x;
        cin>>d>>a>>m>>b>>x;
        int amount=d;
        int setValue=a;
        int elapsed=0;
        bool flag= true;
        while(amount<=x){
            int i;
            for(i=1; i<=m; i++){
                amount+= setValue;
                elapsed+=1;
                if(amount>=x) break;
            }
           
            if(flag){
                setValue= b;
            } else{
                setValue=a;
            }
            flag= !flag;
          //  cout<<"Amount: "<<amount<<" Months: "<<elapsed<<endl;
        }
        cout<<elapsed-1<<endl;
    }
    return 0;
}
