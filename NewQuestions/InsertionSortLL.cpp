#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int data): val(data), next(nullptr){}
};

void insert(ListNode* &head, int data){
    if(head == nullptr) head = new ListNode(data);
    else return insert(head->next, data);
}

void print_ll(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
}

void sorted_insert(ListNode* &head, ListNode* &node){
    if(head == nullptr) { 
        head = node;
        node->next = nullptr;
    }
    else if(head->val >= node->val){
        node->next = head;
        head = node;
    }
    else{
        ListNode* temp =head;
        ListNode* prev = head;
        while(temp!= nullptr and temp->val < node->val){
            prev = temp;
            temp = temp->next; 
        }
        prev->next= node;
        node->next = temp;
    }
}

ListNode* insertion_sort_ll(ListNode* &head){
    ListNode* temp = head;
    ListNode* newHead = nullptr;
    while(temp!= nullptr){
        ListNode* up = temp->next;
        sorted_insert(newHead, temp);
        temp = up;
    }
    return newHead;
}

int main(){
    ListNode* head = nullptr;
    insert(head, 5);
    insert(head, 1);
    insert(head, 6);
    insert(head, 3);
    insert(head, 4);
    insert(head, 2);
    print_ll(head);
    head = insertion_sort_ll(head);
    print_ll(head);
}