#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value){ data = value; next = nullptr;}
};


void insert(Node* &head, int data){
    if(head == nullptr) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = new Node(data);
    return;
}

void print(Node* head);

Node* reverse_ll(Node* &start, Node* &end, Node* prev){
    Node* temp = start;
    while(temp!= end){
        Node* upcoming= temp->next;
        temp->next = prev;
        prev = temp;
        temp = upcoming;
    }
    temp->next = prev;
    return temp;
}

void print(Node* head){
    while(head != nullptr) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

pair<Node*, pair<Node*,Node*>> getP(Node* head, int s, int e){
    Node* start, *end;
    Node* prev = nullptr;
    int cIndex= 1;
    while(cIndex<=e){
        if(cIndex == s-1) prev= head;
        if(cIndex == s) start = head;
        if(cIndex == e) end = head;
        head = head->next;
        cIndex++;
    }
    return make_pair(start, make_pair(end, prev));
}

int length_ll(Node* head){
    int length = 0;
    while(head!= nullptr){
        head = head->next;
        length++;
    }
    return length;
}

int main(){
    Node* head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    cout<<length_ll(head);
    // auto point = getP(head, 1, 5);
    // Node* start= point.first;
    // Node* end= point.second.first;
    // Node* ep = end->next;
    // Node* prev= point.second.second;
    // if(prev) prev->next = reverse_ll(start, end, prev);
    // else head = reverse_ll(start, end, prev);
    // start->next = ep;

    //  print(head);
    // cout<<start->data<<" "<<start->next->data;

}