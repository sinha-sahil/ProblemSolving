#include <iostream>
using namespace std;

long long int cp=0;

int partition(int* arr, int start, int end){
//	cout<<"Came Here too";
    int pivot= arr[start];
    int pIndex= start+1;
    for(int i= start+1; i<=end; i++){
        if(arr[i]<= pivot){
            int temp= arr[i];
            arr[i]= arr[pIndex];
            arr[pIndex]= temp;
            pIndex++;
            cp++;
        }
    }
   	int temp= arr[start];
   	arr[start]= arr[pIndex];
   	arr[pIndex]= temp;
    return pIndex;
}


void quickSort(int* arr, int start, int end){
		if(start>= end) return;
        int pIndex= partition(arr, start, end);
        quickSort(arr, start, pIndex-1);
        quickSort(arr, pIndex+1, end);
}

int main()
{
    int arr[10];
    for(int i=0; i<10; i++){
        cin>>arr[i];
    }
    quickSort(arr, 0, 9);
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

