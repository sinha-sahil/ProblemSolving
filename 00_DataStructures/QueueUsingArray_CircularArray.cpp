#include<iostream>
#include<algorithm>
using namespace std;

class queue{
	public:
		int size;
		int arr[10];
		int front, rear;
		
		queue(): front(-1), rear(-1), size(10){
			fill(arr, arr+9, -1);
		}
		
		bool empty(){
			if(front ==-1 and rear ==-1) return true;
			return false;
		}
		
		bool full(){
			if((rear+1)%size == front) return true;
			return false;
		}
		
		void print(){
			cout<<"Queue: ";
			if(!this->empty()){
				for(int i= front; i<= rear; i++) cout<<arr[i]<<" ";
			} else cout<<"Empty";
			cout<<endl;
		}
		
		void enqueue(int data){
			if(this->full()) {
				cout<<"Full"<<endl;
				return;
			}
			if(this->empty()){
				front++;
				rear= (rear+1)%size;
				arr[rear]= data;
			} else{
				rear= (rear+1) % size;
				arr[rear]= data;
			}
		}
		
		void dequeue(){
			if(this->empty()) return;
			front= (front+1)%size;
			if( front== rear){
				front= rear= -1;
			}
		}
};

int main(){
	queue q;
	q.enqueue(2);
	q.enqueue(15);
	q.enqueue(-12);
	q.enqueue(15);
	q.enqueue(-12);
	q.enqueue(23);
	q.enqueue(151);
	 
	q.enqueue(-9);
	q.print();
	q.enqueue(23);
	q.enqueue(-72);
	q.enqueue(23);
	q.print();
	q.dequeue();
	q.dequeue();
	q.print();
	q.enqueue(21213);
	q.print();	
}
