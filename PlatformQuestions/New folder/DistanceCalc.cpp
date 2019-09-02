#include<bits/stdc++.h>
using namespace std;

int dist_calc(vector<int>& A, vector<int>& B){
	int distance=0;
	for(int i=0; i<A.size()-1; i++){
		distance+= max(abs(A[i]-A[i+1]), abs(B[i]- B[i+1]));
	}
	return distance;
}

int main(){
	int n=4;
	vector<int> A(n), B(n);
	for(int i=0; i<n; i++){
		cin>>A[i]>>B[i];
	}
	cout<<dist_calc(A, B);
}
