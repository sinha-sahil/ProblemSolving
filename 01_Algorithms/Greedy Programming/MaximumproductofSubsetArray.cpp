//maxim
#include<iostream>
using namespace std;

int main(){
	cout<<"Elements: "; int n; cin>>n;
	int *ar= new int[n];
	for(int i=0; i<n; i++) cin>>ar[i];
	int zeroCount=0, posCount=0, negCount=0;
	int maxNeg= ar[0];
	int product= 1;
	for(int i=0; i< n; i++){
		if(ar[i]==0){
			zeroCount++; 
			continue;
		}
		if(ar[i]>0) posCount++;
		else if(ar[i]<0){
			negCount++;
			if(ar[i]> maxNeg) maxNeg= ar[i];
		}
		product *=ar[i];
	}
	if(zeroCount==n or (zeroCount!=0 and negCount==1)) cout<<"0"<<endl;
	else if(negCount%2==0) cout<<product<<endl;
	else if(negCount%2!=0) cout<<product/maxNeg<<endl;
}
