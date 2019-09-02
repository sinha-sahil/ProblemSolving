#include<iostream>
using namespace std;

void print(int** ar){
	int n=3;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}
}

void printer(int* ar){
	for(int i=0; i<5; i++){
		cout<<*ar<<endl;
		ar++;
	}
}
int main(){
	int arr[3][3]={{1,2,3},{4,5,6}, {7,8,9}};
	int ar[5]={1,2,3,4,5};
	cout<<arr<<" "<<*arr<<endl;
	print(arr);
//	for(int i=0; i<3; i++){
//		for(int j=0; j<3; j++){
//			cout<<*(*(arr+i)+j)<<" ";
//		}
//	}
}
