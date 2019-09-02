#include<iostream>
using namespace std;

void res(int& a, int& b, int& s){
	s= a+b;
}

void resValue(int* a, int* b){
	++(*a);
	++(*b);
}

int main(){
	int a,b; cin>>a>>b;
	resValue(&a,&b);
	cout<<a<<" "<<b;
}
