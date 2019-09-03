#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int value): val(value), next(nullptr){}
};

void insert(ListNode* &head, int data){
    if(head == nullptr){
        head= new ListNode(data);
        return;
    }
    ListNode* temp = head;
    while(temp->next!= nullptr) temp = temp->next;
    temp->next = new ListNode(data);
}

// Node* reverse_ll(Node* &start, Node* &end, Node* prev){
//     Node* temp = start;
//     while(temp!= end){
//         Node* upcoming= temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = upcoming;
//     }
//     temp->next = prev;
//     return temp;
// }

ListNode* reverse_ll(ListNode* &start, ListNode* &end, ListNode* prev){
    ListNode* temp = start;
    while(temp!= end){
        ListNode* tx = temp->next;
        temp->next = prev;
        prev= temp;
        temp = tx;
    } 
    temp->next = prev;
    return temp;   
}

void print(ListNode* head){
    cout<<"Print: ";
    while(head != nullptr) {cout<<head->val<<" "; head = head->next;}
    cout<<endl;
}

int ifPalindrome(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* ob = head;
    bool isOdd = false;
    while(slow!=nullptr and fast->next!= nullptr and fast->next->next!= nullptr){
        ob = slow;
        slow = slow->next;
        fast = fast->next->next;
        if(fast->next == nullptr) isOdd = true;
        else if(fast->next->next == nullptr) isOdd = false;
    }
    ListNode* prev = nullptr;
    ListNode* up = slow->next;
    if(isOdd){
        head = reverse_ll(head,ob,prev);
    }
    else{
        head = reverse_ll(head, slow, prev);
    }
    slow = up;
    fast = head;
    while(slow!= nullptr){
        // cout<<slow->val<<" "<<fast->val<<endl;
        if(slow->val != fast->val) return 0;
        slow = slow->next;
        fast = fast->next;
    }
    return 1;
}

int main(){
    ListNode* head = nullptr;
    insert(head, 1);
    insert(head, 3);
    insert(head, 3);
    insert(head, 3);
    insert(head, 1);
    cout<<ifPalindrome(head);
}