#include<iostream>
using namespace std;

struct lruNode{
    int key, val;
    lruNode* left, *right;
    lruNode(int kd ,int vd): key(kd), val(vd), left(nullptr), right(nullptr){}
};

int currSize;
int caps;
lruNode* head, *tail;

void init(int capacity) {
    caps = capacity;
    currSize = 0;
    head = nullptr;
    tail = nullptr;
}

lruNode* find(int key){
    lruNode* temp = tail;
    while(temp){
        if(temp->key == key){
            return temp;
        }
        temp = temp->left;
    }
    return nullptr;
}

void updatePos(lruNode* node){
    if(head == tail || node == tail) return;
    if(node == head){
       head = node->right;
       head->left = nullptr;
       tail->right = node;
       node->left = tail;
       node->right = nullptr;
       tail = node;
    }
    else{
        node->left->right = node->right;
        node->right->left = node->left;
        tail->right = node;
        node->left = tail;
        node->right = nullptr;
        tail = node;
    }
}

int get(int key){
    lruNode* found = find(key);
    if(found) {
        updatePos(found);
        return found->val;
    }
    return -1;
}

void set(int key, int value){
    lruNode* found = find(key);
    if(found){
        found->val = value;
        updatePos(found);
    }
    else{
        if(currSize < caps){
            if(head == nullptr){
                head = new lruNode(key, value);
                tail = head;
            }
            else{
                tail->right = new lruNode(key, value);
                tail->right->left = tail;
                tail = tail->right;
            }
            currSize++;
        }
        else{
            tail->right = new lruNode(key, value);
            tail->right->left = tail;
            tail = tail->right;
            head = head->right;
            head->left = nullptr;
        }
    }
}

int main(){
    init(2);
    set(2,1);
    set(1,1);
    set(2,3);
    set(4,1);
    cout<<get(1)<<endl;
    cout<<get(2);
}

// 7 2 G 2 S 2 6 G 1 S 1 5 S 1 2 G 1 G 2
// -1 -1 5 -1
// -1 -1 2 6

// 6 2
// S 2 1
// S 1 1
// S 2 3
// S 4 1
// G 1 G 2