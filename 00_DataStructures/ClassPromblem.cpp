#include<iostream>
using namespace std;

int main(){
	int size; cout<<"Enter array Size: ";
	int ki; cin>>ki;
	int *ar= new int[ki];
	int *newAr= new int[ki];
	for(int i=0; i<ki; i++) cin>>ar[ki];
	int count=0;
	for(int i=0; i<ki;i++){
		if(ar[i+1]> ar[i]){
			newAr[count]= ar[i+1];
		} else{
			newAr[count]=-1;
		}
		count++;
	}
	cout<<"Data "<<endl;
	for(int i=0; i<ki;i++){
		cout<<" "<<newAr[i];
	}
}
