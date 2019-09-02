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

Node* swapPairs(Node* &head) {
        if((head==nullptr) or (head->next==nullptr)) return head;
        head->next->next = swapPairs(head->next->next);
        Node* temp= head;
        head= head->next;
        temp->next= head->next;
        head->next= temp;
        return head;
}
    

int main(){
	Node* head= NULL;
//	if(head==NULL){
//		cout<<"Create New Link List: ";
//		int data;
//		cout<<"\nEnter data: "; cin>>data;
//		insert(data, 0, head);
//	}
//	bool run = true;
//	while(run){
//		int switch_on;
//		cout<<"Enter Choice: 1. Insert Element, 2. Print Elements: "; cin>>switch_on;
//		switch(switch_on){
//			case 1:
//				cout<<"Enter Data and Position: ";
//				int data; cin>>data;
//				int position; cin>>position;
//				insert(data, position, head);
//				break;
//			case 2:
//				printList(head);
//				break;
//			default:
//				cout<<"Enter Correct Options";
//		}
//		cout<<endl<<"Anoter Operation (1 for Y): "; int c; cin>>c;
//		if(c!= 1) run = false; 
//	}
	insert(1, 0, head);
	insert(2, 1, head);
	insert(3, 2, head);
	insert(4, 3, head);
	printList(head);
	cout<<"\nAfter\n";
	swapPairs(head);
	printList(head);
	return 0;
}
