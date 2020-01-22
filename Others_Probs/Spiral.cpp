#include<iostream>
#include<vector>
using namespace std;

int main(){
	int m, n;
	cin>>m>>n;
	vector<vector<int>> matrix;

	for(int i=0; i<m; i++){
		vector<int> temp;
		int val;
		for(int j=0; j<n; j++){
			cin>>val;
			temp.push_back(val);
		}
		matrix.push_back(temp);
	}
	int fr, fc;
	fr = fc = 0;
	while(fr <m && fc <n){
		for(int i= fc; i<n; i++) cout<<matrix[fr][i]<<" ";
		fr++;
		for(int i= fr; i<m; i++) cout<<matrix[i][n-1]<<" ";
		n--;
		if(fr < m){
			for(int i= n-1; i>=fc; i--) cout<<matrix[m-1][i]<<" ";
			m--;
		}
		if(fc < n){
			for(int i=m-1; i>= fr; i--) cout<<matrix[i][fc]<<" ";
			fc++;	
		}
	}
}