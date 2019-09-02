#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdint>
#include <algorithm>
using namespace std;

struct Node{
    uint64_t data;
    Node* next;
};

Node* last= NULL;
Node* head= NULL;
Node* middle= NULL;
int length=0;

void enque(uint64_t Data){
    Node* newNode = new Node();
    newNode->data= Data;
    newNode->next = NULL;
    if(last==NULL && head==NULL){
        head= newNode;
        last= newNode;
        middle = newNode;
    } else{
        newNode->next= NULL;
     	Node* temp = head;
     	while(temp!= NULL){
     		temp= temp->next
		 }
		 temp->next= newNode;
		 last= newNode;
		 if(length==1){
		 	middle= head;
		 } else{
		 	middle= middle->next;
		 }
    }
    length++;
    //cout<<length<<endl;
}

void printHead(){
    Node* temp = head;
    cout<<temp->data<<endl;
}

void printLast(){
    Node* temp = last;
    cout<<temp->data<<endl;
}

void printMiddle(){
	Node* temp = middle;
	cout<<temp->data<<endl;
}


int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        uint64_t element;
        cin>>element;
        enque(element);
    }
	int q; cin>>q;
	for(int i=0; i<q; i++){
		int choice;
		cin>>choice;
		switch(choice){
			case 1:
				uint64_t data;
				cin>>data;
				enque(data);
				break;
			case 2:
				printMiddle();
				break;
			case 3:
				printHead();
				break;
			case 4:
				printLast();
				break;
			case 5:
				break;
			default:
				cout<<"-1"<<endl;
				
		}
	}
    return 0;
}
