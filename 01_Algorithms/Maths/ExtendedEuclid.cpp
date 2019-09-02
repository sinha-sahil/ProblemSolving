#include<iostream>
#include<cmath>
using namespace std;


int gcd(int a, int b, int *x, int *y){
	if(a==0){
		*x= 0;
		*y= 1;
		return b;
	}
	int x1, y1;
	int gcdResults= gcd(b%a, a, &x1, &y1);
	*x= y1 - (b/a)*x1;
	*y= x1;
	return gcdResults;
}

int main(){
	int num1, num2; 
	cin>>num1>>num2;
	int x, y;
	cout<<"GCD: "<<gcd(num1, num2, &x, &y);
	cout<<endl<<"X: "<<x<<" Y: "<<y;
}
