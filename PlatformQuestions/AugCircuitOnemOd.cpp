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
        int j=1;
        while(j<=m && amount<=x){
            amount+= setValue;
            elapsed+=1;  
		//	cout<<"Amount: "<<amount<<" Months: "<<elapsed<<endl; 
            if(amount>=x){
		//		cout<<"Edher Break hua: "<<amount<<endl;
				break;
			}
			j++;
			if(j>m){
		        if(flag){
        	        setValue= b;
        		}
            	else{
                	setValue=a;
            	}
            	flag= !flag;
            	j=1;
			}
        }
 
        cout<<elapsed-1<<endl;
    }
    return 0;
}
