#include<iostream>
using namespace std;

long long int mod = 1000000007;

int calcExpo(long long int base, long long int exp){
	long long int t= 1;
	while(exp>0){
		if(exp%2!=0)
			t= (t* base)  % mod;
		base= (base*base) % mod;
		exp/=2 ;
	}
	return t%mod;
}

int main(){
	long long int base, exp;
	cin>>base>>exp;
	cout<<calcExpo(base, exp);
}
