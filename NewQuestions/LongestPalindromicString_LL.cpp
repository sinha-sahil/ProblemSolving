#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int data) : val(data), next(nullptr){}
};

void insert(ListNode* &head, int data){
    if(head) return insert(head->next, data);
    else {
        head = new ListNode(data);
        return;
    }
}

void print_ll(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int getSplitLen(ListNode* head1, ListNode* head2){
    int count = 0;
    while(head1 and head2 and head1->val == head2->val){
        count++;
        head1 = head1->next;
        head2 = head2->next;
    }
    return count;
}

int getMaxLenPalindrome(ListNode* head){
    ListNode* temp = head;
    ListNode* newLL = nullptr;
    int maxLen = 1;
    while(temp!= nullptr){
       ListNode* up = temp->next;
       temp->next = newLL;
       maxLen = max(maxLen, 2*getSplitLen(newLL, up)+1);
       maxLen = max(maxLen, 2*getSplitLen(temp, up));
       newLL = temp;
       temp = up;
    }
    return maxLen;
}


int main(){
    ListNode* head = nullptr;
    // insert(head, 2);
    // insert(head, 3);
    // insert(head, 3);
    // insert(head, 3);
    // insert(head, 2);
    // insert(head, 1);
    // insert(head, 2);
    // insert(head, 1);
    // insert(head, 2);
    // insert(head, 2);
    // insert(head, 1);
    // insert(head, 3);
    // insert(head, 2);
    // insert(head, 2);
    // insert(head, 1);
    // insert(head, 3);
    // insert(head, 3);
    // insert(head, 3);
    // insert(head, 3);
    // insert(head, 3);
    // insert(head, 2);
    // insert(head, 2);
    // insert(head, 1);
    // insert(head, 1);
    // insert(head, 3);
    // insert(head, 1);
    // insert(head, 3);
    // insert(head, 1);
    // insert(head, 3);

    insert(head, 1);
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    insert(head, 3);
    insert(head, 1);




    print_ll(head);
    cout<<getMaxLenPalindrome(head);

}

// 1 -> 1 -> 2 -> 3 -> 2 -> 2 -> 3 -> 2 -> 1 -> 3 -> 1

//  1 -> 1 -> 3 -> 1 -> 3 -> 1 -> 3 

// 1 -> 3 -> 3 -> 3 -> 3 -> 3 -> 2 -> 2

// 2 -> 1 -> 2 -> 1 -> 2 -> 2 -> 1 -> 3 -> 2 -> 2

// 3 -> 3 -> 3 -> 3 -> 3 -> 2 -> 2 -> 1 -> 2 -> 1