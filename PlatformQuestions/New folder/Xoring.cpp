#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n1;
		long long int n2;
		cin>>n1>>n2;
		long long int sol=n1;
		for(long long int i=n1+1; i<=n2; i++) sol= sol xor i;
		long long op= sol%2;
		if(not op) cout<<"Even";
		else cout<<"Odd";
		cout<<endl;
	}
}
