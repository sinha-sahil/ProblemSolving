#include<iostream>
using namespace std;

void swap(int &a, int &b){
    a = a+b;
    b = a-b;
    a = a-b;
}

void print(int* arr, int s);

void insertion_sort(int* arr, int s){
    for(int i=0; i<s; i++){
        int k = i-1;
        while(k>=0 && arr[k+1]<arr[k]){
            int temp = arr[k+1];
            arr[k+1] = arr[k];
            arr[k] = temp;
            k--;
        }
    }
}


5 -> 2 -> 3 -> 1 ->4


ListNode* insertion_sort(ListNode* head){
    ListNode* temp = head->next;
    ListNode* prev = head;
    ListNode* finalHead = head;
    while(temp!= nullptr){
        ListNode* curr = prev;
        while(curr)
    }
}


void print(int* arr, int s){
    for(int i=0; i<s; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int* arr;
    int size;
    cin>>size;
    arr = new int[size];
    for(int i=0; i<size; i++) cin>>arr[i];
    cout<<endl;
    print(arr, size);
    insertion_sort(arr, size);
    print(arr,size);
}