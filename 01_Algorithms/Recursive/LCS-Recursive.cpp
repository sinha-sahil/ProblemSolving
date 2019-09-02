#include<iostream>
using namespace std;

string x, y;

int lcs(int m, int n){
	if(m==0 || n==0) return 0;
	else{
		if(x[m]==y[n]) return (1 + lcs(m-1, n-1) );
		else{
			return max(
				lcs(m-1, n),
				lcs(m, n-1)
			);
		}
	}
	
}

int main(){
	int m,n;
	cout<<"Enter Strings: "; cin>>x>>y;
	m= x.length();
	n= y.length();
	cout<<"LCS Length: "<<lcs(m, n);
}
