#include<iostream>
using namespace std;

ListNode* getIntersection(ListNode* A, ListNode* B){
    ListNode* h1 = A;
    ListNode* h2; = B;
    bool fh = true;
    bool fs = true;
    while(h1 != h2){
        if(not fh and not fs) return nullptr;
        if(h1->next == nullptr) {
            h1->next = B; 
            fh = false;
        }
        if(h2->next == nullptr) {
            h2->next = A;
            fs = false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1;
}