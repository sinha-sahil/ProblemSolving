#include<iostream>
using namespace std;

int power(int x, int y, int p){
	int result= 1;
	x%= p;
	while(y>0){
		if(y%2!=0){
			result= (result*x) % p;
		}
		y= y/2;
		x= (x* x) %p;
	}
	return result;
}

int main(){
	cout<<power(2,3,5);
}
