#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int value): val(value), next(nullptr){}
};

void insert(ListNode* &head, int value){
    if(head == nullptr) head = new ListNode(value);
    else{
        ListNode* temp = head;
        while(temp->next!=nullptr) temp = temp->next;
        temp->next = new ListNode(value);
    }
}

ListNode* reverse_ll(ListNode* &start, ListNode* &end, ListNode* prev){
    ListNode* temp = start;
    while(temp!= end){
        ListNode* up = temp ->next;
        temp->next = prev;
        prev = temp;
        temp = up;
    }
    temp->next = prev;
    return temp;
}

ListNode* k_reverse(ListNode* &head, int k){
   if(head == nullptr) return head;
   ListNode* start, *end;
   int j= 0;
   while(j<k){
       if(j == 0){
           start = head;
           end = head;
       }
       else end = end->next;
       j++;
   }
   ListNode* prev = k_reverse(end->next, k);
   return reverse_ll(start, end, prev);
}

void print(ListNode* head){
    while(head!= nullptr){
        cout<<head->val<<" ";
        head = head->next;
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
    insert(head, 8);
    // print(head);
    ListNode* newHead = k_reverse(head, 2);
    print(newHead);

}