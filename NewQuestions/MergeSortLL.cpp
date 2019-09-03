#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int data) : val(data), next(nullptr){}
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

ListNode* get_ll_mid(ListNode* start){
    ListNode* slow = start;
    ListNode* fast = start;
    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

void merge_sort_ll(ListNode* &start){
    if(start->next){
        ListNode* mid = get_ll_mid(start);
        ListNode* fh = start;
        ListNode* sh = mid ->next;
        mid->next= nullptr;
        merge_sort_ll(fh);
        merge_sort_ll(sh);
        start=  merge_ll(fh, sh);
    }
}

int main(){
    ListNode* head = nullptr;
    insert(head, 3);
    insert(head, 2);
    insert(head, 5);
    insert(head, 1);
    insert(head, 6);
    insert(head, 4);
    print_ll(head);
    merge_sort_ll(head);
    cout<<endl;
    print_ll(head);


}