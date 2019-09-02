#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool primeTest(int n){
	if(n==1) return false;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
	vector<int> vi;
	int n; cin>>n;
	for(int i=2; i<=sqrt(n); i++){
		if(primeTest(i) && n%i==0){
			int t= n;
			while(t%i==0){
				vi.push_back(i);
				t= t/i;
			}
		}
	}
	cout<<"Factors: ";
	for(int i=0; i<vi.size(); i++){
		cout<<vi[i]<<" ";
	}
}
