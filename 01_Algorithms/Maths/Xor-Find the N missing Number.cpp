#include<iostream>
using namespace std;

int main(){
	int n; cin>>n;
	int* ar= new int[n];
	int* ar2= new int[n-1];
	for(int i=0; i<n-1; i++){
		cin>>ar2[i];
	}
	int xorOne= ar2[0];
	int xorTwo=1;
	for(int i=1; i<n-1; i++){
		xorOne^= ar2[i];
	}
	for(int i=2; i<=n; i++){
		xorTwo^= i;
	}
	int result= xorOne^xorTwo;
	cout<<result<<endl;

}
