#include<iostream>
using namespace std;

int maxPrime(int n){
	int pFactor;
	if(n%2==0){
		pFactor=2;
		n/=2;
	}
	for(int i=3; i*i<n+1; i++){
		while(n%i ==0){
			n/=i;
			pFactor=i;
		}
	}
	if(n>2) pFactor= n;
	return pFactor;
}

int main(){
	int n, p;
	cin>>n>>p;
	if(maxPrime(n)<=p) cout<<"P Smooth"; else cout<<"Nopes"<<endl;
}
