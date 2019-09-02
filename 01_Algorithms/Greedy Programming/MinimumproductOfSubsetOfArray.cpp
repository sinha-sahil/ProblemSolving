#include<iostream>
#include<vector>
using namespace std;

int main(){
	cout<<"#Elements: "; int n; cin>>n;
	int* ar= new int[n];
	for(int i=0; i<n; i++) cin>>ar[i];
	int zeroCount=0, minPos= ar[0], maxNeg=ar[0];
	int negCount=0, posCount=0;
	int prod= 1;
	for(int i=0; i<n; i++){
		if(ar[i]==0) {
			zeroCount++;
			continue;
		}
		else if(ar[i]<0){
			if(maxNeg< ar[i]){
				maxNeg= ar[i];
			}
			negCount++;
		}
		else if(ar[i]>0){
			if(minPos> ar[i]){
				minPos=ar[i];
			}
			posCount++;
		}
		prod*= ar[i];
	}
	if(zeroCount!=0 && negCount==0) cout<<"0"<<endl;
	else if(negCount==0 && zeroCount==0) cout<<minPos<<endl;
	else if(negCount%2==0) cout<<prod/maxNeg<<endl;
	else cout<<prod<<endl;
}

