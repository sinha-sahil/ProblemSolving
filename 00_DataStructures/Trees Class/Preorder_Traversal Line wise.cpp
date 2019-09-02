#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int data;
	Node* left, *right;
	Node(int value){
		data= value;
		left= nullptr;
		right= nullptr;
	}
};

void printLevelWise(Node* root){
	if(root== nullptr) return;
	queue<Node*> q;
	q.push(root);
	q.push(nullptr);
	while(q.size()!=1){
		Node* frnt = q.front();
		if(frnt){
			q.pop();
			cout<<frnt->data<<" ";
			if(frnt->left) q.push(frnt->left);
			if(frnt->right) q.push(frnt->right);
		}
		else{
			q.pop();
			q.push(nullptr);
		}
	}
}

bool checkCousins(Node* root, Node* a, Node* b){
	if(root== nullptr) return 0;
	int la, lb, xparent, yparent;
	queue<Nod*> q;
	q.push(root);
	q.push(nullptr);
	int level=0;
	while(q.size()!=1){
		Node* current= q.front();
		q.pop();
		if(current){
			if(current->left){
				if(current->left->data == a->data){
					la= level;
					xparent= current->data;
				}
				if(current->right->data== b->data){
					lb= level;
					yparent= current->data;
				}
			}
			if(current->right){
				if(current->right->data == a->data){
					la= level;
					xparent= current->data;
				}
				if(current->right->data== b->data){
					lb= level;
					yparent= current->data;
				}
			}
		}
		else{
			q.push(nullptr);
			level++;
		}
	}
	if(la == lb and xparent!= yparent) true;
	return false;
	
}

bool testSiblings(int dataOne, int dataTwo){
	
}



int main(){
	
}
