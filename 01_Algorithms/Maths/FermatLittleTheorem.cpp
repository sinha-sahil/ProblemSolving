#include<iostream>
#include<cmath>
using namespace std;

int main(){
	bool prime= false;
	int n;
	cin>>n;
	for(int i=2; i<=n-1; i++){
		int pRes= pow(i, n-1);
		if(pRes%n==1) prime= true;
		else prime= false;
	}
	cout<<prime;
	return 0;
}o
