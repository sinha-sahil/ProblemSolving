#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int data): val(data), next(nullptr){}
};

void insert(ListNode* &head, int data){
    if(head == nullptr){
        head = new ListNode(data);
        return;
    }
    else return insert(head->next, data);
}

ListNode* reverse_ll(ListNode* &start, ListNode* &end, ListNode* prev){
    ListNode* temp = start;
    while(temp!= end){
        ListNode* up = temp->next;
        temp->next = prev;
        prev = temp;
        temp = up;
    }
    temp->next = prev;
    return temp;
}

void print_ll(ListNode* head){
    while(head!= nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

bool ifPalindrome(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    bool even = false;
    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast->next == nullptr) even = false;
        else if(fast->next->next == nullptr) even = true;
    }
    ListNode* newHead;
    ListNode* prev = nullptr;
    if(even){
        newHead = reverse_ll(slow->next, prev, prev);
    }
    else {
        newHead = reverse_ll(slow, prev, prev);
    }
    print_ll(newHead);
    print_ll(head);
    return 1;

}

int main(){
    ListNode* head= nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    cout<<ifPalindrome(head);
}