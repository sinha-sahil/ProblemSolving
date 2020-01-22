#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int data): val(data), next(nullptr){}
};

ListNode* head = nullptr;
int currSize = 0;

void insert(int position, int data){
    if(position == 1){
        ListNode* newNode = new ListNode(data);
        newNode ->next = head;
        head = newNode;
        currSize++;
    }
    else{
        if(position > currSize+1) return;
        ListNode* temp = head;
        int index = 1;
        while(index < position-1) {
            temp = temp->next;
            index++;
        }
        ListNode* newNode = new ListNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
        currSize++;
    }
}

void print_ll(){
    ListNode* temp = head;
    while(temp!= nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

void deleteNode(int position){
    if(position> currSize) return;
    else if(position == 1){
        head = head->next;
        currSize--;
        return;
    }
    else {
        ListNode* temp = head;
        int cIndex= 1;
        while(cIndex< position-1){
            cIndex++;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        currSize--;
        return;
    }
}

ListNode* reverse_ll(ListNode* &start, ListNode* end, ListNode* prev){
    ListNode* temp = start;
    while(temp!= end){
        cout<<temp->next<<" "<<prev<<endl;
        ListNode* nn = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nn;
        cout<<temp->next<<" "<<prev<<endl;

    }
    cout<<start->next<<" "<<end->next->val<<endl;
    return prev;
}

ListNode* kreverse_ll(ListNode* a, int k){
    ListNode* start= a;
    ListNode* end = a;
    ListNode* prev = nullptr;
    ListNode* temp = a;
    int cCount = 1;
    ListNode* newHead = a;
    bool found = false;
    
    while(temp!=nullptr){
        if(cCount == k){
            ListNode* nn = end->next;
            prev = reverse_ll(start, end, prev);
            cout<<prev->val<<endl;
            if(not found){
                cout<<"NewHeadSet"<<endl;
                found = true;
                newHead = prev;
            }
            temp = nn;
            start =  temp;
            end = temp;
            cCount =1;
        }
        else{
            cCount++;
            temp = temp->next;
            end = temp;
        }
    }
    cout<<newHead->val<<endl;
    return newHead;
}

int main(int argc, const char * argv[]) {
    insert(1, 101);
    insert(2, 102);
    insert(3, 103);
    insert(4, 104);
    insert(5, 105);
    insert(6, 106);
    print_ll();
    cout<<endl;
    head = kreverse_ll(head,2);
    // cout<<"came here";
    // cout<<head->val;
//    head = kreverse_ll(head, 2);
    cout<<endl;
    print_ll();
   
    return 0;
}
