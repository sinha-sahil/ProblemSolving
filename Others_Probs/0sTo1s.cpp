#include<iostream>
#include<vector>
using namespace std;

int main(){
	int m, n;
	cin>>m>>n;
	vector<int> temp(n);
	vector<vector<int>> vi(m, temp);
	for(int i=0; i<m; i++) for(int j=0; j<n; j++) cin>>vi[i][j];

	bool fRow = false;
	bool fCol = false;

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if (i == 0 && vi[i][j] == 0) fRow = true;
			if (j == 0 && vi[i][j] == 0) fCol = true;
			if(vi[i][j] == 0) vi[0][j] = vi[i][0] = 0;
		}
	}

	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			if(vi[i][j] == 1) if (vi[0][j] == 0 or vi[i][0] == 0) vi[i][j] = 0;
		}
	}
	if(fRow) for(int i=0; i<n; i++) vi[0][i] = 0;
	if(fCol) for(int j=0; j<m; j++) vi[j][0] = 0;

	for(int i=0; i<m; i++) {for(int j=0; j<n;j++) cout<<vi[i][j]<<" "; cout<<endl;}
}