#include<iostream>
using namespace std;

void swap(int& a, int& b){
	int temp= a;
	a= b;
	b= temp;
}

void printArray(int* arr, int n){
	for(int i=0; i<n; i++) cout<<arr[i]<<" ";
	cout<<endl;
}

int getLeft(int i){ return i*2 + 1;}
int getRight(int i){ return i*2 +2;}

void heapify(int* arr, int n, int i){
	while( getLeft(i)<n){
		int greaterIndex = getLeft(i);
		if(getRight(i)<n and arr[greaterIndex]< arr[getRight(i)]){
			greaterIndex= getRight(i);
		}
		if(arr[i]> arr[greaterIndex]) break;
		else{
			swap(arr[i], arr[greaterIndex]);
			i= greaterIndex;
		}
	}	
}


void heapSort(int* arr, int n){
	for(int i=n/2-1; i>=0; i--){
		heapify(arr, n, i);
	}
	for(int i=n-1; i>=0; i--){
		swap(arr[i], arr[0]);
		heapify(arr,i,0);
	}
}

int main(){
	int n;
	cin>>n;
	int* arr= new int[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	heapSort(arr,n);
	printArray(arr, n);
}
