#include<iostream>
using namespace std;

class heap_util{
	public:
		int* arr;
		int size;
	
		
		int getRight(int i){ 
			return (i*2)+2;
		}
		
		int getLeft(int i){
			return (i*2)+1;
		}
		
		int getParent(int i){
			return (i-1)/2;
		}
		
		void swap(int& a, int& b){
			int temp= a;
			a= b;
			b=a;
		}
		
};

class min_heap: heap_util{
	int total;
	public:
		
		min_heap(int n): total(n){
			arr= new int[n];
			size= 0;
		}
		
		void insert(int value){
			if(size>= total) return;
			arr[size]= value;
			size++;
			heapifyUp();
		}
		
		int getMin(){
			if(size==0) return -1;
			return arr[0];
		}
		
		int extractMin(){
			if(size>0){
				int temp= arr[size-1];
				swap(arr[0], arr[size-1]);
				size--;
				heapifyDown();
				return temp;	
			}
			return -1;
		}
		
		void heapifyUp(){
			int i= arr[size-1];
			while(getParent(i)>=0 and arr[i]< arr[getParent(i)]){
				swap(arr[i], arr[getParent(i)]);
				i= getParent(i);
			}
		}
		
		void heapifyDown(){
			int i=0;
			while(getLeft(i) <size){
				int smallerIndex= getLeft(i);
				if(getRight(i) < size and arr[smallerIndex]> arr[getRight(i)]){
					smallerIndex= getRight(i);
				}
				if(arr[smallerIndex]> arr[i]) break;
				else{
					swap(arr[i], arr[smallerIndex]);
					i= smallerIndex;
				}
			}
		}
		
		void printHeap(){
			cout<<"Heap: ";
			for(int i=0; i<size; i++){
				cout<<arr[i];
			}
			cout<<endl;
		}
		
};

int main(){
	min_heap mhp(100);
	mhp.insert(1);
	mhp.insert(2);
	mhp.insert(3);
	mhp.insert(5);
	mhp.insert(4);
	mhp.insert(6);
	mhp.insert(0);
	mhp.printHeap();
	cout<<"MinExtract: "<<mhp.extractMin()<<endl;
	cout<<"MinExtract: "<<mhp.extractMin()<<endl;
	mhp.printHeap();	
}
