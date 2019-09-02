#include<iostream>
using namespace std;

int add(int x, int y){
	while(y>0){
		int carry= x & y;
		x= x xor y;
		y= carry<<1;
	}
	return x;
}

int main(){
	//cout<<add(14,52);
	cout<<"a\u";
}
