#include<iostream>
using namespace std;

int main(){
	int m=4;
	const int n=5;
	const int* p= &n;
	//n= 6;
//	*p= 7;
	p= &m;
	*p =8;
}
