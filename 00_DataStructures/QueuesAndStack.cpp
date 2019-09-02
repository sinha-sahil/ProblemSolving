#include<iostream>
#include<queue>
#include<stack>
using namespace std;
// To reverse the stack and queue;

int main(){
	stack<int> si;
	queue<int> qi;
	cout<<"Stack (old): ";
	
	// initialising the queue
	for(int i=1; i<10; i++){
		si.push(i);
		cout<<si.top()<<" ";
	}
	while(!si.empty()){
		qi.push(si.top());
		si.pop();
	}
	cout<<"\nQueue: ";	
	while(!qi.empty()){
		si.push(qi.front());
		qi.pop();
		
	}
}
