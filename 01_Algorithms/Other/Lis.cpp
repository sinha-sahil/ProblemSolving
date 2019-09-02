#include<iostream>
using namespace std;

int findLisLength(int ar[], int size){
	int* a= new int[size];
	for(int k=0; k<size; k++) a[k]=1;
	for(int i=1; i<size; i++){
		for(int j=0; j<i; j++){
			if(ar[i]>ar[j]){
				a[i]= max(a[i], a[j]+1);
			}
		}
	}
	return a[size-1];
}

int main(){
	int n;
	cout<<"Array Length: ";
	cin>>n;
	int* ar= new int[n];
	cout<<"Array: ";
	for(int i=0; i<n;i++) cin>>ar[i];
	int result= findLisLength(ar, n);
	cout<<"Lis Length: "<<result;
	
}
