#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int s, int m, int e){
	int s1= m-s+1;
	int s2= e-m;
	vector<int> ar1(s1);
	vector<int> ar2(s2);
	int index =0;
	for(int i=s; i<=m; i++) ar1[index++]= arr[i];
	index =0;
	for(int i=m+1; i<=e; i++) ar2[index++] = arr[i];

	int total = e-s +1;
	int x=0, y=0;
	int k= s;
	while(x<s1 or y<s2){
		if(x>=s1){
			arr[k] = ar2[y];
			y++;
			k++;
		}
		else if(y>=s2){
			arr[k]= ar1[x];
			x++;
			k++;
		}
		else if(ar1[x]< ar2[y]){
			arr[k] = ar1[x];
			k++;
			x++;
		}
		else if(ar1[x]>ar2[y]){
			arr[k] = ar2[y];
			k++;
			y++;
		}
		else if(ar1[x] == ar2[y]){
			arr[k] = ar1[x]; x++; k++;
			arr[k] = ar2[y]; y++; k++;
		}
	}
}

void mergeSort(vector<int>& arr, int start, int end){
	if(start<end){
		int mid = start + (end-start)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main(){
	int s;
	cin>>s;
	vector<int> arr(s);
	for(int i=0; i<s;i++) cin>>arr[i];

	mergeSort(arr, 0, s-1);
	for(int i=0; i<s;i++) cout<<arr[i];

}

// a b c d e 
// a b c
// d e

// a b c e
