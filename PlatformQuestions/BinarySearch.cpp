#include <iostream>
#include <vector>
#include <cmath>

//chriopratic codebabes Thursday
using namespace std;

bool binarySearch(int key, vector<int>& vi){
	int high= vi.size();
	int low= 0;
	while(low<high){
		int mid= (high+low)/2;
		if(key == vi[mid]){
			return true;
		}
		else if(key<vi[mid]){
			high= mid-1;
		}
		else if(key>vi[mid]){
			low= mid+1;			
		}
	}
	return false;
}

bool primeTest(int n){
    if(n==2) return true;
    if(n==1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}

void generatePrime(int n,vector<int>& vi){
    int lastElement= vi[vi.size()-1]+1;
    while(n>=lastElement){
        if(primeTest(lastElement)){
            vi.push_back(lastElement);
        }
        lastElement++;
    }
}


int main(){
	vector<int> vi;
	vi.push_back(2);
	int t; cin>>t;
	for(int i=0; i<t; i++){
		bool flag= false;
		int n; cin>>n;
		if(n<= vi[vi.size()]){
			for(int k=0; k<vi.size(); k++){
				int temp = n - vi[k];
				if(binarySearch(temp, vi)){
					flag= true;
					break;
				} 
			}
		} else{
			generatePrime(n, vi);
			for(int k=0; k<vi.size(); k++){
				int temp = n - vi[k];
				if(binarySearch(temp, vi)){
					flag= true;
					break;
				} 
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
