#include<iostream>
using namespace std;

bool gcdCheck(int n, int a){
	if(n==1) return true;
	for(int x=1; x< n; x++){
		if((a*x)%n ==1)
		return true;
	}
	return false;
}

int main(){
	unsigned long long int number;
	cin>>number; 
	unsigned long long int count=1;
	for(int i=2; i<number; i++){
		int modValue=number%i;
		if(modValue!=0){
			if(gcdCheck(modValue, i)) {
				count++;
			}
		}
	}
	cout<<count;
}
