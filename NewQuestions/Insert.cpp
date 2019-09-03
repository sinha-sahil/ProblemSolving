#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int data): val(data), next(nullptr){}
};

void insert(ListNode* &head, int val){
    if(head == nullptr){
        head = new ListNode(val);
        return;
    }
    return insert(head->next, val);
}

void insert_in_head(ListNode* &head, ListNode* newNode){
    if(head == nullptr){
        head = newNode;
        return;
    }
    return insert_in_head(head->next, newNode);
}

bool ifSpecial(int number){
    long long int sum_value = 0;
    while(number>0){
        sum_value += number%10;
        number = number/10;
    }
}