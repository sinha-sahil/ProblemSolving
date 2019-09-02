#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* prev;
	Node* next;
	Node(int x){
		data= x;
		next= nullptr;
	}
};

Node* last=nullptr;

void insert(Node* &head){
	int data;
	cout<<"Data: "; cin>>data;
	Node* temp= new Node(data);
	if(head==nullptr){
		temp->prev= nullptr;
		head= temp;
		last= temp;
	} else{
		Node* cur= head;
		while(cur->next!= nullptr){
			cur= cur->next;
		}
		cur->next= temp;
		temp->prev= cur;
		last= temp;
	}
}

void remove(){
	cout<<"Will do";
}

void print(Node* &head){
	Node* temp= head;
	while(temp!=nullptr){
		cout<<"Prev: "<<temp->prev<<" Data: "<<temp->data<<" Next: "<<temp->next<<endl;
		cout<<temp->data<<" ";
		temp= temp->next;
	}
	cout<<endl<<"Reverse: ";
	temp=last;
	while(temp!=nullptr){
		cout<<temp->data<<" ";
		temp=temp->prev;
	}
	cout<<endl;
}

int main(){
	Node* head= nullptr;
	insert(head); insert(head); insert(head); insert(head); insert(head);
	print(head);
//	cout<<"dobly linked list";
//	cout<<endl;
//	int choice;
//	while(true){
//		cout<<"Choice: "; cin>>choice;
//		switch(choice){
//		case 1: insert(head);  break;
//		case 2: remove(); break;
//		case 3: print(head); break;
//		default: cout<<"Enter correct option"; break;
//		}
//		int go; cout<<"Another Go: ";
//		cin>>go; if(go==0) break;
//	}
}
