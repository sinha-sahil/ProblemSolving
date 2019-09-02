#include<iostream>
#include<math.h>
using namespace std;

bool primeTest(int number){
	if(number ==1){
		return false;
	}
	for(int i=2; i<=sqrt(number); i++){
		if(number%i==0)
		return false;
	}
	return true;
}

int main(){
	int t; cin>>t;
	for(int i=0; i<t; i++){
		int start, end;
		cin>>start>>end;
		for(int i= start; i<=end; i++){
			if(primeTest(i)){
				cout<<i<<endl;
			}
		}
	}
}
