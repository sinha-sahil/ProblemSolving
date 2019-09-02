#include<iostream>
using namespace std;

int binarySearch(int ar[], int low, int high, int key){
	if(low>high) return -1;
	int mid= low+ (high-low)/2;
	if(ar[mid] == key) return mid;
	if(ar[low] <= ar[mid]){
		if(key >= ar[low] and key<= ar[mid])
			return binarySearch(ar, low, mid-1, key);
		return binarySearch(ar, mid+1, high, key);
	}
	if( key>= ar[mid] and key<=ar[high])
		return binarySearch(ar, mid+1, high, key);
	return binarySearch(ar,low, mid-1, key);
}

 int search(int nums[], int key, int n) {
        int low= 0; int high= n-1;
        while(low<high){
            int mid= low + (high- low)/2;
            if(nums[mid]== key) return mid;
            if(nums[low] <=nums[mid]){
                if(nums[low]<= key and key<=nums[mid]){
                    high= mid-1;
                }
                else{
                    low= mid+1;
                }
            }
            else{
                if(nums[mid]<= key and key<= nums[high])
                    low= mid+1;
                else
                    high= mid-1;
            }
        }
        return -1;
        
}
int main(){
	int n; cin>>n;
	int* ar=  new int[n];
	for(int i=0; i<n; i++) cin>>ar[i];
	int key; cin>>key;
//	cout<<binarySearch(ar,0, n-1, key);
	cout<<endl;
	cout<<search(ar,key, n);
}
