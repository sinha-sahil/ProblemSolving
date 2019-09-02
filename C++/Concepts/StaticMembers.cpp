#include<iostream>
using namespace std;

class Person{
	public:
		static int data;
		
		Person(){
		}
};
int Person::data= 1;

class p1: public Person{
	public:
		int d1;
		p1(){
			d1= data;
			data++;
		}
};

class p2: public Person{
	public:
		int d2;
		p2(){
			d2= data;
			data++;
		}
};


int main(){
	Person o1;
	p1 o2;
	p2 o3;
	p1 o4;
	p2 o5;
	cout<<o1.data<<" "<<o2.d1<<" "<<o3.d2<<" "<<o4.d1<<" "<<o5.d2<<endl;
}
