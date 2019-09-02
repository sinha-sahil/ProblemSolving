#include<iostream>
using namespace std;

int main(){
	int n; cin>>n;
	int* ar= new int[n];
	int max_elem;
	int index;
	for(int i=0; i<n; i++){
		cin>>ar[i];
		if(i==0) max_elem= ar[0];
		else{
			if(ar[i]> max_elem){
				max_elem= ar[i];
				index= i;
			}
		}
	}
	cout<<index;
}
