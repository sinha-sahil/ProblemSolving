#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> temp(n);
	vector<vector<int>> vi(n, temp);
	int currValue = 1;
	int sR= 0, sC= 0;
	int m = n, n_ = n;
	while(sR<m && sC< n){
		for(int i=sC; i<n_; i++) vi[sR][i] = currValue++;
		sR++;
		for(int i=sR; i<m; i++) vi[i][n_-1] = currValue++;
		n_ --;
		if(sR < m){
			for(int i= n_ -1; i >= sC; i--) vi[m-1][i] = currValue++;
			m--;
		}
		if(sC < n_){
			for(int i=m -1; i>= sR; i--) vi[i][sC] = currValue++;
			sC++;
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cout<<vi[i][j]<<" ";
		cout<<endl;
	}

}