#include<iostream>
using namespace std;

int fastFib(int n, int ar[]){
	if(n==0) return 0;
	if(n==1) return 1;
	else{
		if(ar[n-1]== NULL){
			ar[n-1]= fastFib(n-1, ar[]);
		}
		if(ar[n-2]== NULL){
			ar[n-2]= fastFib(n-2, ar[]);
		}
		ar[n]= ar[n-1]+ ar[n-2];
	}
}

int main(){
	int n;
	cout<"Enter Series Length: ";
	cin>>n;
	int *ar= new int[n];
	ar={NULL};
	cout<"Enter Elements: ";
	for(int i=0; i<n; i++) cin>>ar[i];
	fastFib(n);
	cout<<"FiboSeries: ";
	for(int i=0; i<n; i++) cout<<ar[i]<<" ";
	return 0;
}
