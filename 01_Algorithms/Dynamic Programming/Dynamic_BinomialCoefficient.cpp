#include<iostream>
#include<cmath>
using namespace std;

int binomialCoeff(int n, int k){
	int ar[n+1][k+1];
	for(int i=0; i<=n; i++){
		for(int j=0; j<=min(i, k); j++){
			if(j==0 || j==i)
				ar[i][j]=1;
			else
				ar[i][j]= ar[i-1][j-1] + ar[i-1][j];
		}
	}
	return ar[n][k];
}


int main(){	cout<<binomialCoeff(5,2);
}
