
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head = NULL;

void insertIntoList() {
	Node* newNode = new Node();
	cout << "Enter New Data: "; 
	cin>> newNode->data;
	newNode->next = head;
	head = newNode;
}

void deleteFromList() {
	cout << "Will see";
}
void printList() {
	Node* temp = head;
	cout << endl << "List Contents" << endl;
	cout << "Head Details:  pointer: " << head->next << endl;
	while (temp != NULL){
		cout << "Data: " << temp->data << endl;
		temp = temp->next;
	}
}

int main()
{
	
	if (!head) {
		cout << "Create A new Link List";
		cout << endl << "Enter Data 1: ";
		int newData; cin >> newData;
		Node* newNode = new Node();
		newNode->data = newData;
		newNode->next = NULL;
		head = newNode;
	}
	bool run = true;
	while (run) {
		int switch_on;
		cout << endl << "Enter a operation Choice (1->Insert, 2->Delete, 3->Print)"; cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			insertIntoList();
			break;
		case 2:
			deleteFromList();
			break;
		case 3:
			printList();
			break;
		default:
			cout << "Enter correct Choice" << endl;
			break;
		}
		cout << "Perform Another Opertaions (1->Yes)"; int reRun; cin >> reRun;
		if (reRun != 1) run = false;
	}
    return 0;
}


