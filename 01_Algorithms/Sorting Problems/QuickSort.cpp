#include<iostream>
using namespace std;


int partition(int* arr, int start, int end){
	int pivot= arr[end];
	int pIndex= start;
	for(int i=start; i<end; i++){
		if(arr[i]<=pivot){
			int temp= arr[i];
			arr[i]= arr[pIndex];
			arr[pIndex]= temp;
			// swap(arr[i], arr[pIndex]
			pIndex++;
		}
		for(int z=start; z<=end; z++) cout<<arr[z]<<" ";
		cout<<endl;
	}
	int temp= arr[pIndex];
	arr[pIndex] = arr[end];
	arr[end]= temp;
	return pIndex;
}

void quickSort(int* arr, int start, int end){
	if(start>=end) return;
	int pIndex= partition(arr, start, end);
	quickSort(arr, start, pIndex-1);
	quickSort(arr, pIndex+1, end);
}

int main(){
	int n; cin>>n;
	int* arr= new int[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	quickSort(arr, 0, n-1);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}
