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

ListNode* reverse_ll(ListNode* &start, ListNode* &end, ListNode* prev){
    ListNode* temp = start;
    while(temp!=end){
        ListNode* up = temp->next;
        temp->next= prev;
        prev= temp;
        temp = up;
    }
    if(not temp) return prev; 
    temp->next = prev;
    return temp;
}

void print(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

ListNode* merge_ll(ListNode* &head1, ListNode* &head2){
    ListNode* newHead = head1;
    while(head1!= nullptr and head2!= nullptr){
        ListNode* up = head1->next;
        head1->next= head2;
        ListNode* up2 = head2->next;
        head2->next= up;
        head1 = up;
        head2 = up2;
    }

    return newHead;
}

ListNode* solve(ListNode* head){
    ListNode* head1 = head;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next and fast->next->next){
        slow = slow ->next;
        fast = fast->next->next;
    }
    ListNode* head2 = slow->next;
    ListNode* end2 = nullptr;
    ListNode* prev = nullptr;
    slow->next = nullptr;
    head2 = reverse_ll(head2, end2, prev);
    head1 = merge_ll(head1, head2);
    return head1;
}

int main(){
    ListNode* head = nullptr;
    insert(head, 1);
    insert(head, 2);
    // insert(head, 3);
    // insert(head, 4);
    // insert(head, 5);
    // insert(head, 6);
    // insert(head, 7);
    // insert(head, 8);
    // insert(head, 9);
    print(head);
    ListNode* prev = nullptr; ListNode* end = nullptr;
    print(head);
    solve(head);
    print(head);
    
}