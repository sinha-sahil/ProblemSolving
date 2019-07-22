#include<iostream>
#include<vector>
using namespace std;


int main(){
	int n; 
	cin>>n;
	vector<vector<int>> matrix;
	for(int i=0; i<n; i++){
		vector<int> temp;
		int val;
		for(int j=0; j<n; j++) {cin>>val; temp.push_back(val);}
		matrix.push_back(temp);
	}

	for(int i=n-1; i>=0; i--){
		int adder = 0;
		int s_= 0;
		for(int j=0; j<n; j++)
			if(i+adder < n) s_+= matrix[j][i+(adder++)];
		cout<<s_<<" ";
	}

	int row = 1;
	while(row < n){
		int cur= row;
		int col = 0;
		int s_ =0;
		while(cur<n) s_+=matrix[cur++][col++];
		cout<<s_<<" ";
		row++;
	}

}