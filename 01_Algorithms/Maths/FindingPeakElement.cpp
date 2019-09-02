#include<iostream>
using namespace std;

int findPeak(int ar[], int low, int high, int n){
	int mid= low + (high-low)/2;
	if((mid==0 || ar[mid]>=ar[mid-1]) && (mid==n || ar[mid] >=ar[mid+1])) return ar[mid];
	else if(mid>0 && ar[mid]<ar[mid-1]) return findPeak(ar, low, mid-1, n);
	else return findPeak(ar, mid+1, high,n);
}

int main(){
	int n; cin>>n;
	int* ar=new int[n];
	for(int i=0; i<n; i++) cin>>ar[i];
	cout<<findPeak(ar,0,n-1, n);
}
