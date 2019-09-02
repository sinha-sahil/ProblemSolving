#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int count=1;

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

int main(){
	vector<int> vi;
	vi.push_back(2);
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n;
		cin>>n;
		if(n<=count){
			cout<<vi[n-1]<<endl;
		} else{
			for(int k=vi[count-1]+1; k<=1299800; k++){
				if(primeTest(k)){
					vi.push_back(k);
					count++;
				}
				if(count==n) break;
			}
			cout<<vi[n-1]<<endl;
		}
	}
}
