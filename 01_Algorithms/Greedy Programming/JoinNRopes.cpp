#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int join_ropes(int ar[], int n){
	int total=0;
	vector<int> vi;
	for(int i=0; i<n; i++){
		vi.push_back(ar[i]);
		while(vi.size()>1){
			sort(begin(vi), end(vi));
			total+= vi[0]+ vi[1];
			vi.push_back(vi[0]+ vi[1]);
			vi.erase(begin(vi), begin(vi)+2);
		}
	}
	return total;
}

int main(){
	int ar[]={4,2,5,6};
	int n= sizeof(ar)/sizeof(ar[0]);
	cout<<join_ropes(ar, n);
}
