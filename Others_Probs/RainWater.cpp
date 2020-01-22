#include<iostream>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int* arr= new int[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        int* lmax= new int[n];
        int* rmax= new int[n];
        int cmax= 0;
        for(int i=n-1; i>=0; i--){
            if(cmax < arr[i]){
                cmax= arr[i];
            }
            rmax[i] = cmax;
        }
        rmax[n-1]=0;
        for(int i=0; i<n; i++) cout<<rmax[i]<<" ";
        cout<<endl;
        cmax= 0;
        for(int i=0; i<n; i++){
            if(arr[i] >cmax){
                cmax= arr[i];
            }
            lmax[i]= cmax;
        }
        lmax[0]= 0;
        for(int i=0; i<n; i++) cout<<lmax[i]<<" ";
        cout<<endl;
        int store= 0;
        for(int i=0; i<n; i++){
           int min_value= min(lmax[i], rmax[i]);
            int val= min_value- arr[i];
            if(val >0){
                store +=val;
            }
        }
        cout<<store<<endl;   
    }
	return 0;
}

0 1 1 2 2 2 2 3 3 3 3 3 
0 1 1 2 2 2 2 3 3 3 3 3 

1 2 2 2 3 3 3 3 3 3 3 0
3 3 3 3 3 3 3 3 2 2 2 0