#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void add(int data, Node* &last){
	Node* newNode= new Node;
	newNode->data= data;
	if(last==NULL){
		newNode->next = newNode;
		last= newNode;
	} else{
		newNode->next= last->next;
		last->next = newNode;
		last= newNode;
	}
}

int front(Node* &last){
	if(last==NULL){
		return -1;
	}
	return last->next->data;
}

/*
void pop(Node* &last){
	if(last==NULL){
		return;
	}
	last= last->next->next;
}
*/

int pop(Node* &last){
	if(last==NULL) return -1;
	Node* curr= last->next;
	int data= curr->data;
	if(last->next== last)
		last= NULL:
	else last->next = last->next->next;
	delete curr;
	return data;
	
}

int main(){
	Node* last= NULL;
	add(2, last);
	add(3, last);
	pop(last);
	cout<<front(last);
}
