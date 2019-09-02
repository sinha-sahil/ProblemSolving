#include<iostream>
using namespace std;
int digits(int n){
	int dig=0;
	int count=0;
	if(n%2==0){
		while(n%2==0){
			count++;
			n/=2;
		}
		if(count>1) dig+=2;
		else if(count==1) dig++;
	}
	for(int i=3; i*i<n+1; i++){
		count=0;
		while(n%i==0){
			count++;
			n/=i;
		}
		if(count>1) dig+=2;
		else if(count==1) dig++;
	}
	return dig;
}

int main(){
	int n;
	cin>>n;
	int n2= n;
	int digCount=0;
	while(n2>0){
		digCount++;
		n2/=10;
	}
	cout<< (digits(n)< digCount);
}
