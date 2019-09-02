#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool primeTest(int n){
	if(n==0 || n==1) return false;
	for(int i=2; i<n; i++) if(n%i==0) return false;
	return true;
}

void generatePrime(int n, vector<int> &vi){
	while(vi.size()!=n){
		for(int k= vi[vi.size()-1])
	}
}

int main(){
	vector<int> vi;
	vi.push_back(2);
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n;
		cin>>n;
		if(n<= vi.size()){
			cout<<n*vi[n-1]+n<< endl;
		} else{
			generatePrime(n, &vi);
			cout<<n*vi[n-1]+n<< endl;
		}
	}
	
}
