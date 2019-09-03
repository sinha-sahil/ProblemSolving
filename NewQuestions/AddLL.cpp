#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int data): val(data), next(nullptr){}
};


ListNode* add(ListNode* head1, ListNode* head2){
    ListNode* newHead = nullptr;
    ListNode* temp = newHead;
    int carry = 0;
    int v1, v2, result;
    while(head1 != nullptr or head2!= nullptr){
        if(head1 == nullptr) v1 = 0; else v1 = head1->val;
        if(head2 == nullptr) v2 = 0; else v2 = head2->val;
        int result = v1+ v2+ carry;
        carry = 0;
        if(result >9){
            result -=10;
            carry = 1;
        }
        if(newHead == nullptr){
            newHead = new ListNode(result);
            temp = newHead;
        }
        else{
            temp->next = new ListNode(result);
            temp = temp->next;
        }
        if(head1!= nullptr) head1 = head1->next;
        if(head2!= nullptr) head2 = head2->next;
    }
    
    if(carry){
        temp->next = new ListNode(carry);
        temp = temp->next;
    }

    return newHead;
}