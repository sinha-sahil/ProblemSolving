#include<iostream>
using namespace std;

void inPlaceLeftRotate(int ar[], int digits, int length){
    for (int j = 0; j < digits; j++) {
        int temp = ar[0];
        for (int i = 0; i < length; i++) {
            ar[i] = ar[i + 1];
        }
        ar[length - 1] = temp;
    }
}


int main(){
    int n, d;
    cin>>n>>d;
    int *array= new int[n];
    for(int i=0; i<n; i++) cin>>array[i];
    inPlaceLeftRotate(array, d, n);
    for(int i=0; i<n; i++) cout<<array[i]<<" ";
}
