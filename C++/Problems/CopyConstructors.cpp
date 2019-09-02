#include<iostream>
using namespace std;

class ClassName{
	int value;
	int value2;
	public:
		ClassName(int a, int b): value(a), value2(b){
		}
		ClassName(const ClassName& obj){
			cout<<"Copy called"<<endl;
			value= obj.value;
			value2= obj.value2;
		}
		
		void printMem(){
			cout<<&value<<" "<<&value2<<endl;
		}

};

int main(){
	ClassName c1(20,30);
	cout<<"C1: "; c1.printMem();
	ClassName c2= c1;
	cout<<"C2: "; c2.printMem();
}
