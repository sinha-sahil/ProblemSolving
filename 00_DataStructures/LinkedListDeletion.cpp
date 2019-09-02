#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;	
};

void reverse(Node* &head){
	Node* temp= head;
	Node* nextNode;
	Node* prevNode= NULL;
	while(temp!=NULL){
		nextNode= temp->next;
		temp->next= prevNode;
		prevNode= temp;
		temp= nextNode;
	}
	head= prevNode;	
}

void printData(Node* &head){
	Node* temp= head;
	cout<<endl<<"Data: ";
	while(temp!=NULL){
		cout<<temp->data<<endl;
		temp= temp->next;
	}
	cout<<endl;
}

void deleteData(Node* &head){
	cout<<"Index: ";
	Node* temp= head;
	int index; cin>>index;
	int ind=0;
	while(ind<index-1){
		temp= temp->next;
		ind++;
	}
	if(temp== head){
		head= temp->next;
		delete temp;
	} else{
		Node* delNode= temp->next;
		temp->next= temp->next->next;
		delete delNode;
	}
}


void insertData(Node* &head){
	cout<<endl<<"Data: ";
	Node* newNode= new Node();
	cin>>newNode->data;
	Node* temp= head;
	while(temp->next != NULL){
		temp= temp->next;
	}
	temp->next= newNode;
	cout<<endl;
}

int main(){
	Node* head= NULL;
	if(head==NULL){
		cout<<"1st Node Data: ";
		Node* newNode= new Node();
		cin>>newNode->data;
		newNode->next = NULL;
		head= newNode;
	}
	cout<<"1. Insert 2. Delete 3.Print 4.Reverse"<<endl;
	int choice; 
	while(true){
		cout<<"Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				insertData(head);
				break;
			case 2:
				deleteData(head);
				break;
			case 3:
				printData(head);
				break;
			case 4:
				reverse(head);
				break;
			default:
				cout<<"Enter correct option"<<endl;
		}
	//	cout<<"Another opertation (1-> yes. 2->No): "; int ch; cin>>ch;
	//	if(ch==2) break;
	}
	return 0;
}
