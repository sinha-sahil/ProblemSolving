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
	
	return 0;
}
