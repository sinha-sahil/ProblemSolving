#include<iostream>
#include<vector>
using namespace std;
//Number whose only prime factors are 2, 3 or 5.

vector<long long int> vi;

int nthUgly(int n){

	long long int nxTwo= 2;
	long long int nxThree= 3;
	long long int nxFive= 5;
	int i2=0, i3=0, i5=0;
	for(int i=0; i<150; i++){
		long long int nextugly= min(nxTwo, min(nxThree, nxFive));
		vi.push_back(nextugly);
		if(nextugly== nxTwo){
			i2++;
			nxTwo= vi[i2]*2; 		
		}
		if(nextugly== nxThree){
			i3++;
			nxThree= vi[i3]*3;
		}
		if(nextugly== nxFive){
			i5++;
			nxFive= vi[i5]*5;
		}
	}
	return vi[n-1];
}

int main(){
	vi.push_back(1);
	cout<<nthUgly(150);
}
