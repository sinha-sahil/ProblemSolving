#include<iostream>
using namespace std;

void fun(int data, int val){
	cout<<data<<" "<<val<<endl;
}

void fun(double data, int val){
	cout<<data<<" "<<val<<endl;
}

int main(){
	int data1= 2;
	double data2= 2.2;
	int adata2= 3;
	double data3= 3.3;
	fun(adata2, data2);
}
