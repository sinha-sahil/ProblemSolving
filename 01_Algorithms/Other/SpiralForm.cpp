#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> output;
	int m, n;
	cout<<"Rows and Col.: ";
	cin>>m>>n;
	int matrix[m][n];
	cout<<"Matrix: "<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>matrix[i][j];
		}
	}
	int fr=0, fc=0;
	while(fr<m and fc<n){
		for(int i=fc; i<n; i++){
			output.push_back(matrix[fr][i]);
		}
		fr++;
		for(int i=fr; i<m; i++){
			output.push_back(matrix[i][n-1]);
		}
		n--;
		if(fr<m){
			for(int i=n-1; i>= fc; i--){
				output.push_back(matrix[m-1][i]);
			}
			m--;
		}
		if(fc<n){
			for(int i=m-1; i>=fr; i--){
				output.push_back(matrix[i][fc]);
			}
			fc++;
		}
	}
	cout<<endl;
	for(auto i: output){
		cout<<i<<" ";
	}
}
