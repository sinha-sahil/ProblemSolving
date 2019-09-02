#include<iostream>
using namespace std;

template <class T>
T maxOne(T const& t1, T const& t2){
	return t1<t2?t1:t2;
}

int main(){
	cout<<maxOne(20,'A');
}
