#include<iostream>
using namespace std;

long long int power(long long int base, long long int e, long long int p){
	long long int res=1;
	base= base%p;
	while(e){
		if(e&1)
			res= (res*base)%p;
		e= e>>1;
		base= (base*base) %p;
	}
	return res;
}

bool check_print(long long int n){ 		// Fermat's little theorem
	if(n<=1 || n==4) return false;
	if(n<=3) return true;
	for(int i=0; i<3; i++){
		long long int a= 2+ rand() % (n-4);
		if(power(a, n-1, n)!=1) return false;
	}
	return true;
}


int main(){
	cout<<power(2,4,10000);
	return 0;
}

// Every elemente occurs 2^n-1 times in the set of subsets of its original set.
// (n* (n+1)/2) *  2^n-1 :: we will get the sum of elements of all subsets.
// we can utilize the power method to calculate if a number is prime or not using fermat's little theorem
