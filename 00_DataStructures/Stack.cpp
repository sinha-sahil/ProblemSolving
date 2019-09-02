#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void insert(int info, int position, Node* &head){
	if(position==0 && head==NULL){
		Node* newNode= new Node();
		newNode->data= info;
		newNode->next= NULL;
		head= newNode;
	} else if(position==0){
		Node* newNode= new Node();
		newNode->data= info;
		newNode->next= head;
		head= newNode;
	} else if(position>0){
		int indexCount=0;
		Node* temp= head;
		while(indexCount<position-1){
			temp= temp->next;
			indexCount++;
		}
		Node* newNode= new Node();
		newNode->data= info;
		newNode->next=  temp->next;
		temp->next= newNode;
	}
}


void push(Node* &head, int data, int& position){
	int location= position+1;
	insert(data, location, head);
	position+=1;
}

void pop(Node* head, int& top){
	Node* temp= head;
	Node* prev;
	int location= top+1;
	for(int i=0; i<=location; i++){
		temp= temp->next;
		if(i==location-1){
			prev = temp;
		}
	}
	prev->next= NULL;
	delete temp;
	top--;
}

void printList(Node* &head){
	Node* temp= head;
	cout<<endl<<"Linked List Data: ";
	while(temp!= NULL){
		cout<<temp->data<<" ";
		temp= temp->next;
	}
}

int main(){
	Node* head= NULL;
	int top=-1;
	int bottom=-1;
	if(top==-1){
		cout<<"Empty Stack "<<endl<<"Enter Data to push: ";
		int data;
		cin>>data;
		push(head, data, top);
	}
	bool run= true;
	while(run){
		int switch_on;
		cout<<"Enter Choice (1. Push, 2. Pop, 3. Print): "; cin>>switch_on;
		
		switch(switch_on){
			case 1:
				int data; cout<<"Enter data: "; cin>>data;
				push(head, data, top);
				break;
			case 2:
				pop(head, top);
				break;
			case 3:
				printList(head);
				break;
			default:
				cout<<"Enter Correct Choice"<<endl;
				
		}
		cout<<endl<<"Carry out Another (1: Yes): "; int choice; cin>>choice; if (choice!=1) run = false;
	}
}
