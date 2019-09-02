#include<iostream>
using namespace std;

struct Node{
	int data;
	int priority;
	Node* next;
};

void insertion(Node* &head, int dat, int priori){
	Node* newNode= new Node();
	newNode->data= dat;
	newNode->priority= priori;
	newNode->next = NULL;
	Node* temp = head;
	while(temp->priority> priori && temp->next != NULL){
		temp= temp->next;
	}
	newNode->next= temp->next;
	temp->next = newNode;
}

void printer(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<endl<< "Data: "<< temp->data;
		cout<<endl<<"Priority: "<<temp->priority;
		temp= temp->next;
	}
}

int main(){
	Node* head = NULL;
	cout<<"Priority Queue\n";
	if(head==NULL){
		Node* newNode= new Node();
		cout<<"Enter Data For New Node: "; cin>>newNode->data;
		cout<<"Priority: "; cin>>newNode->priority;
		newNode->next = NULL;
		head= newNode;
	}
	bool run= true;
	while(run){
		cout<<endl<<"Enter Choice: 1-> Insertion; 2->Printing: ";
		int switch_on;
		cin>>switch_on;
		switch(switch_on){
			case 1:
					cout<<"Enter Data: "; int dat; cin>>dat;
					cout<<"Enter Priority: "; int prior; cin>>prior;
					insertion(head, dat, prior);
					break;
				
				case 2:
					printer(head);
					break;
				default: 
					cout<<"Enter Correct choice";
			}
			cout<<endl<<"Another Operation: 1. Yes"; int reRun; cin>>reRun; if(reRun!=1) run= false;
		}
}
