#include<iostream>
using namespace std;

void printArray(int* arr, int n){
	cout<<"Array: ";
	for(int i=0; i<n; i++) cout<<arr[i]<<" ";
	cout<<endl;
}

void swap(int& a, int& b){
	int temp= a;
	a= b;
	b= temp;
}

void bubbleSort(int* arr, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1-i; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
		printArray(arr, n);
	}
}


int main(){
	int n; cin>>n;
	int* arr= new int[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	bubbleSort(arr, n);
	printArray(arr, n);
}
