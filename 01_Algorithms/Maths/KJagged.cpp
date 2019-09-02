#include<iostream>
using namespace std;

bool testJagg(int n, int k){
	if(n%2==0) return (k<=2);
	else{
		for(int i=3; i*i<n; i+=2){
			if(n%i==0)
			return(k<=i);
		}
	}
	return (k<=n);
}


int main(){
	while(true){
		int n, k; cin>>n>>k;
		cout<<testJagg(n,k)<<endl;
	}
	
}
