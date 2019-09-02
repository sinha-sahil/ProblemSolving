#include<iostream>
#include<vector>
using namespace std;

int countFactor(int n){
	vector<bool> primefactors(n+1, true);
	for(int i=2; i*i< n+1; i++){
		if(primefactors[i]){
			for(int k= i*2; k<n+1; k+=i)
			primefactors[k]= false;
		}
	}
	int total=1;
	for(int i=2; i<=n; i++){
		if(primefactors[i]){
			int count=0;
			while(n%i==0){
				n= n/i;
				count++;
			}
			total = total * (count+1);
		}
	}
	return total;
}


int main(){
	int n; cin>>n;
	cout<<countFactor(n);
}
