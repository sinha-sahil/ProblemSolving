#include<iostream>
using namespace std;

ListNode* createRandom(ListNode* head){
    ListNode* newHead = nullptr;
    ListNode* temp = nullptr;
    ListNode* curr = head;
    while(curr!= nullptr){
        if(newHead == nullptr){
            newHead = new ListNode(curr->val);
            temp = newHead;
        }
        else {
            temp->next = new ListNode(curr->val);
            temp = temp->next;
        }
        curr = curr->next;
    }

    curr = head;
    temp = newHead;

    while(curr!= nullptr && temp!= nullptr){
        ListNode* up = curr->next;
        temp->random = curr;
        curr->next= temp;
        temp = temp->next;
        curr= up;
    }

    temp = newHead;

    while(temp!= nullptr){
        temp->random = temp->random->random->next;
        temp = temp->next;
    }

    return newHead;
}