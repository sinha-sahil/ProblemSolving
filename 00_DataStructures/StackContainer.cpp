#include<iostream>
#include<vector>
using namespace std;

class stack{
	public:
		vector<int> stack;
		int minElement;
		int getElement(){
			return minElement;
		}
		bool isEmpty(){
			if(stack.size()==0) return true;
			return false;
		}
		void push(int x){
			if(stack.size()==0){
				stack.push_back(x);
				minElement= x;
			} else{
				if(x>=minElement) stack.push_back(x);
				else{
					int temp= x;
					x= 2*x- minElement;
					minElement= temp;
					stack.push_back(x);
				}
			}
		}
		int pop(){
			if(stack.size()==0){
				cout<<"Empty";
			} else{
				int last= stack[stack.size()-1];
				stack.pop_back();
				if(last<minElement){
					int temp= minElement;
					minElement= 2*minElement - last;
					return temp;
				} else{
					return last;
				}
			}
		}
		void printStack(){
			cout<<"Stack: ";
			for(auto i: stack) cout<<i<<" ";			
			cout<<endl;
		}
};

int main(){
	stack s1;
	s1.push(12);
	s1.push(2);
	s1.push(-1);
	s1.push(3);
	s1.push(8);
	s1.printStack();
	cout<<"Pop: "<<s1.pop()<<endl;
	cout<<"minimum: "<<s1.getElement()<<endl;
	cout<<"Pop: "<<s1.pop()<<" "<<s1.pop()<<endl;
//	s1.printStack();
	cout<<"minimum: "<<s1.getElement();
}
