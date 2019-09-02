// Array problem 2
#include<iostream>
using namespace std;

void leftShift(int ar[], int n, int d){
	
}

int main(){
    int n, d;
    cin>>n>>d;
    int* ar= new int[n];
    for(int i=0; i<n; i++)
        cin>>ar[i];
    leftShift(ar,n,d);
    for(int i=0; i<n; i++)
        cout<<ar[i]<<endl;
    return 0;
}
