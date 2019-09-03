#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int value): val(value), next(nullptr){}
};

void insert(ListNode* &head, int data){
    if(head == nullptr) head = new ListNode(data);
    else return insert(head->next, data);
}

void print(ListNode* head){
    while(head!= nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void delete_dups(ListNode* &head){
    ListNode* temp = head;
    while(temp!=nullptr){
        ListNode* current = temp->next;
        while(current!= nullptr and current->val == temp->val){
            current = current->next;
        }
        temp->next = current;
        temp = temp->next;
    }
}
// 1 -> 2 -> 2-> 3 -> 4

ListNode* modified_delete_dups(ListNode* head){
    ListNode* temp = head;
    ListNode* prev = nullptr;
    ListNode* nHead = nullptr;
    while(temp!= nullptr){
        ListNode* current = temp->next;
        while(current!= nullptr and current->val == temp->val){
            current = current->next;
        }
    
        if(nHead == nullptr and current == temp->next){
            nHead = temp;
            prev = nHead;
        }
        else if(current == temp->next){
            prev->next = temp;
            prev = temp;
        }
        temp = current;
    }
    return nHead;
}

int main(){
    ListNode* head = nullptr;
    insert(head, 1);
    insert(head, 1);
    insert(head, 2);
    insert(head, 2);
    insert(head, 3);
    insert(head, 3);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 5);
    insert(head, 5);
    insert(head, 6);
    insert(head, 6);

    insert(head, 7);
    insert(head, 7);
    insert(head, 7);
    insert(head, 8);
    insert(head, 8);
    insert(head, 8);
    insert(head, 9);
    insert(head, 10);
    insert(head, 10);
    insert(head, 10);
    insert(head, 11);
    insert(head, 12);
    insert(head, 12);
    insert(head, 14);
    print(head);
    head = modified_delete_dups(head);
    print(head);
}