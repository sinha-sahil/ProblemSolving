#include<iostream>
using namespace std;

int factorial(int value){
	if(value==1){
		return 1;
	} else{
		int fValue=1;
		for(int i=value; i>1; i--){
			fValue*= i;
		}
		return fValue;
	}
}

int main(){
	cout<<factorial(12);
}
