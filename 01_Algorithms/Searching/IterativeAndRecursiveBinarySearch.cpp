#include<iostream>
using namespace std;

int itBinarySearch(int ar[], int key, int n){
	int low= 0;
	int high= n-1;
	while(low<= high){
		int mid= low + (high-low)/2;
		if(ar[mid]== key) return mid;
		else if(key > ar[mid]) low= mid+1;
		else if(key< ar[mid] ) high= mid-1;
	}
	return -1;
}

int recBinarySearch(int ar[], int low, int high, int key){
	if(high < low) return -1;
	int mid= low + (high- low)/2;
	if(ar[mid] == key) return mid;
	if(ar[mid]<key) return recBinarySearch(ar, mid+1, high, key);
	else return recBinarySearch(ar,low, mid-1, key);
}

int main(){
	int n; cin>>n;
	int* ar= new int[n];
	for(int i=0; i<n; i++) cin>>ar[i];
	int key; cin>>key;
	cout<<itBinarySearch(ar, key, n);
	cout<<endl;
	cout<<recBinarySearch(ar, 0, n-1, key);
}
