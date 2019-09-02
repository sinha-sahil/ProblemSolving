#include <iostream>
#include <cmath>

using namespace std;

bool primeTest(int n){
    if(n==2) return true;
    if(n==1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}


int main() {
	for(int i=0; i<t; i++){
		int n; cin>>n;
		bool flag= false;
		for(int k=2; k<n; k++){
			int temp = n - k;
			if(primeTest(k) && primeTest(temp)){
				flag= true;
				break;
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
