#include<iostream>
#include<algorithm>
using namespace std;

int dp_lcs(string x, string y){
	int m= x.length();
	int n= y.length();
	int dp_table[m][n];
	fill(&dp_table[0][0], &dp_table[m][n], 0);
	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			if(x[i]== y[j]){
				dp_table[i][j]= 1+ dp_table[i-1][j-1];
			} else{
				dp_table[i][j]= max(
					dp_table[i-1][j],
					dp_table[i][j-1]
				);
			}
		}
	}
	return dp_table[m-1][n-1];
}

int main(){
	cout<<"Strings: ";
	string x, y;
	cin>>x>>y;
	cout<<dp_lcs(x,y);	
}
