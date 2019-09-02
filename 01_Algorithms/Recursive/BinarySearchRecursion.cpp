#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key){
	if(low<high){
		int mid= low + (high-low)/2;
		cout<<"Mid: "<<mid<<" high: "<<high<<" low: "<<low<<" Mid element: "<<arr[mid]<<endl;
		if(key== arr[mid]){
			return mid+1;
		} else if(key< arr[mid]){
			return binarySearch(arr,low, mid-1, key);
		} else if(key> arr[mid]){
			return binarySearch(arr,mid+1, high, key);
		}
	}
	else return -1;
}

int main(){
	int ar[]={22, 55, 77, 89, 93};
	cout<<endl<<binarySearch(ar,0, 5, 55);
}
