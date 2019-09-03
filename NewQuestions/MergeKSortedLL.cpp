#include<iostream>
using namespace std;

ListNode* merge_ll(ListNode* head1, ListNode* head2){
    ListNode* ftemp = head1;
    ListNdoe* stemp = head2;
    ListNode* newHead = nullptr;
    ListNode* temp = nullptr;
    while(ftemp && stemp){
        if(ftemp->val <= stemp->val){
            if(newHead  == nullptr){
                newHead = ftemp;
                temp = newHead;
            }
            else{
                temp->down = ftemp;
                temp = temp->down;
            }
            ftemp = ftemp->down;
        }
        else{
            if(newHead == nullptr){
                newHead = stemp;
                temp = newHead;
            }
            else {
                temp->down = stemp;
                temp = temp->down;
            }
            stemp = stemp->down;
        }
    }

    while(ftemp){
        temp->down = ftemp;
        ftemp = ftemp->down;
        temp = temp->down;
    }
    while(stemp){
        temp->down = stemp;
        stemp = stemp->down;
        temp = temp->down;
    }
    return newHead;
}

ListNode* merge_k_ll(ListNode* head){
    ListNode* newHead = nullptr;
    ListNode* temp = head;
    while(temp!= nullptr){
        ListNode* up = temp->right;
        temp->right = nullptr;
        newHead = merge_ll(newHead, temp);
        temp = up;
    }
    return newHead;
}


7 2 
G 2 -> -1
S 2 6 -> ok
G 1 -> -1
S 1 5 -> ok
S 1 2 -> ok
G 1 
G 2