#include<iostream>
#include<math.h>
#include<vector>
#include<string>

using namespace std;

vector<int> vi;

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

void primeNumbers(int start, int end){
	for(int i= start; i<=end; i++){
		if(primeTest(i)){
			vi.push_back(i);
		}
	}
}

int main(){
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int start, end;
		cin>>start>>end;
		primeNumbers(start,end);
		for(int i=0; i<vi.size(); i++){
			if(vi[i]<10){
				continue;
			} else{
				int sum=0;
				while(sum>=0 && sum<10){
					
				}
			}
		}
	}
}
