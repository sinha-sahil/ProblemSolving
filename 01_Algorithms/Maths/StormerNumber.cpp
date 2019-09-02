#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int maxPrime(int n){
	int pFactor;
	if(n%2==0){
		pFactor=2;
		while(n%2==0)
		n= n/2;
	}

	for(int i=3; i<=sqrt(n); i+=2){
		while(n%i==0){
			n= n/i;
			pFactor=i;
		}
	}
	if(n>2) pFactor= n;
	return pFactor;
}

vector<int> getStormers(int n){
	int count=0;
	vector<int> vi;
	int i=1;
	while(count!=n){
		if(maxPrime(i*i + 1) >=(i*2) ){
			vi.push_back(i);
			count++;
		}
		i++;
	}
	return vi;
}

int main(){
	vector<int> result= getStormers(25);
	for(auto a: result){
		cout<<a<<" ";
	}
}
