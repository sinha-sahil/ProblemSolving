#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n; cin>>n;
	int* ar= new int[n];
	for(int i=0; i<n; i++) cin>>ar[i];
	vector<int> lis(n,1);
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(ar[i]>ar[j] && lis[i]<lis[j]+1){
				lis[i]= lis[j]+1;
			}
		}
	}
	auto mVal= *max_element(begin(lis), end(lis));
	cout<< mVal;
}
