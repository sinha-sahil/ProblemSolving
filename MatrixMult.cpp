#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generateInput(int m, int n){
	vector<vector<int>> matrix;
	for(int i=0; i<m; i++){
		int val;
		std::vector<int> temp;
		for(int i=0; i<n; i++){
			cin>>val;
			temp.push_back(val);
		}
		matrix.push_back(temp);
	}
	return matrix;
}

int main(){
	int m1, n1, m2, n2;
	cin>>m1>>n1;
	vector<vector<int>> matrixOne = generateInput(m1, n1);
	cin>>m2>>n2;
	vector<vector<int>> matrixTwo = generateInput(m2, n2);
	vector<int> output;
	for(int i=0; i<m1; i++){
		for(int j=0; j<n2; j++){
			int value = 0;
			for(int k=0; k<n1; k++)
				value += matrixOne[i][k] * matrixTwo[k][j];
			cout<<value<<" ";	
		}
		cout<<endl;
	}
}