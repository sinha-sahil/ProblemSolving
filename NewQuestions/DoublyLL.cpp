#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next, *prev;

    ListNode(int data) : val(data), next(nullptr), prev(nullptr){}
};

void insert(ListNode* &head, int data){
    if(head == nullptr){
        head = new ListNode(data);
        return;
    }
    else if(head->next == nullptr){
        head->next = new ListNode(data);
        head->next->prev = head;
        return;
    }
    return insert(head->next, data);
}

void print(ListNode* head){
    cout<<"Forward: ";
    while(head->next!= nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<head->val;
    cout<<endl<<"Backward ";
    while(head!= nullptr){
        cout<<head->val<<" ";
        head = head->prev;
    }
    cout<<endl;
}

int main(){
    ListNode* head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    print(head);

}