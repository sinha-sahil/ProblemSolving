#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
//	Node* prev;
	Node(int x){
		data= x;
		next= nullptr;
	}
};

void push(Node* &top){
	int data; cout<<"Data: ";cin>>data;
	Node* temp= new Node(data);
	if(top==nullptr){
		top= temp;
	//	temp->prev= nullptr;
	}
	else {
		temp->next=top;
		top= temp;
//		temp->prev= top;
//		top->next= temp;
//		top= temp;
	}
}

void pop(Node* &top){
	Node* cur= top;
	if(top!=nullptr){
		cout<<"Poping: "<<top->data<<" ";
		top= top->next;
//		top= top->prev;
		delete cur;
	}
	cout<<endl;
}

void print(Node* &head){
	cout<<endl<<"List: ";
	Node* temp= head;
	while(temp!= nullptr){
		cout<<temp->data<<" ";
		temp= temp->next;
	}
	cout<<endl;
}


int main(){
	Node* head= nullptr;
	Node* top= head;
	push(top); push(top); push(top); push(top); push(top);
	print(top);
	pop(top); pop(top); pop(top); print(top); pop(top); pop(top);
	print(top);
}
