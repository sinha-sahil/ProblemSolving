#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n; cin>>n;
	int* ar= new int[n];
	for(int i=0; i<n; i++) cin>>ar[i];
	int m= sqrt(n);
	int key; cin>>key;
	int low=0;
	int high= low+m;
	while(!(ar[low] <= key and ar[high] >= key) and (high<n)){
		if(key >=ar[high]){
			low+= m;
			high+=m; 
		}
		else if(key <= low){
			low-=m;
			high-=m;
		}
	}
	bool found= false;
	for(int i=low; i<=high; i++){
		if(key == ar[i]){
			cout<<"Found "<<i<<endl;
			found= true;
		}
	}
	if(!found) cout<<"Not Found"<<endl;
}
