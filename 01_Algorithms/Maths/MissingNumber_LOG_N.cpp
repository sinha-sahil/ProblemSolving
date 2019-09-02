#include<iostream>
using namespace std;

int main(){
	int n; cin>>n;
	int* ar= new int[n];
	for(int i=0; i<n; i++) cin>>ar[i];
	int low=0; int high= n-1;
	while(low<=high){
		int mid= low + (high-low)/2
		if( ar[mid]!= mid+1 and ar[mid-1]== mid){
			cout<<mid+1;
			break;
		}
		else if( ar[mid] != mid+1){
			high= mid-1;
		} else{
			low= mid+1;
		}
	}
	return 0;
}
