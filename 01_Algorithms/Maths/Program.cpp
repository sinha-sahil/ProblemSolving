#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

bool primeTest(int n){
    if(n==2) return true;
    if(n==1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}

void generatePrime(int n, vector<int>& vi){
    int lastEle= vi[vi.size()-1] + 1;
    while(vi.size()<=n){
        if(primeTest(lastEle)){
            vi.push_back(lastEle);
        }
        lastEle++;
    }
}

int main() {
	int t;
	cin>>t;
	vector<int> vi;
	vi.push_back(2);
	for(int i=0; i<t; i++){
	    int n;
	    cin>>n;
	    if(n<= vi.size()){
	        cout<< (n* vi[n-1]) + n<<endl;
	    } else {
	        generatePrime(n, vi);
	        cout<< (n* vi[n-1]) + n<<endl;
	    }
	}
	return 0;
}
