#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int value): val(value), next(nullptr){}
};

void insert(ListNode* &head, int data){
    if(head == nullptr) {
        head = new ListNode(data); 
        return;
    }
    return insert(head->next, data);
}

void print(ListNode* head){
    while(head!= nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

ListNode* merge_ll(ListNode* hf, ListNode* hs){
    if(hf == nullptr) return hs;
    if(hs == nullptr) return hf;
    ListNode* newHead;
    ListNode* curr;
    if(hf->val <= hs->val){
        newHead = hf;
        curr= newHead;
        hf = hf->next;
    }
    else{
        newHead = hs;
        curr= newHead;
        hs = hs->next;
    }
    while(hf!= nullptr and hs!= nullptr){
        if(hf->val <= hs->val){
            curr->next = hf;
            hf = hf->next;
            curr = curr->next;
        }
        else{
            curr->next = hs;
            hs = hs->next;
            curr = curr->next;
        }
    }

    if(hf){
        curr->next = hf;
    }
    else {
        curr->next = hs;
    }

    return newHead;
}

int main(){
    ListNode* head1 = nullptr;
    ListNode* head2 = nullptr;
    insert(head1, 12);
    insert(head1, 22);
    insert(head1, 27);
    insert(head2, 4);
    insert(head2, 7);
    insert(head2, 12);
    insert(head2, 46);
    print(head1);
    print(head2);
    ListNode* newx = merge_ll(head1, head2);
    print(newx);
}
// [ 7 -> 12 -> 46 