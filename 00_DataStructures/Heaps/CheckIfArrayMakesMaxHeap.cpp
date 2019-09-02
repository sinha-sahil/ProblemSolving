#include<iostream>
using namespace std;

int getLeft(int i){
	return i*2 +1; 
}

int getRight(int i){
	return i*2+2;
}

bool checkHeap(int* arr, int parent, int n){
	bool value, value2;
	if(getLeft(parent)>n or getRight(parent)>n){
		return true;
	}
	if(getLeft(parent)<n and arr[getLeft(parent)]<arr[parent]){
		if(getRight(parent)< n and arr[getRight(parent)]<arr[parent]){
			value= checkHeap(arr, getLeft(parent), n);
			value2= checkHeap(arr, getRight(parent), n);
		}
		else if(getRight(parent)<n){
			return false;
		}
		else return true;
	}
	else{
		return false;
	}
	return value&value2;
}

int main(){
	int n;
	cin>>n;
	int* arr= new int[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<checkHeap(arr,0, n);
}
