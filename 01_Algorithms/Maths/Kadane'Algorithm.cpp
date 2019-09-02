#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int start=0, end=0, s=0;
	int* ar= new int[n];
	for(int i=0; i<n; i++) cin>>ar[i];
	int max_total= INT_MIN;
	int max_till =0;
	for(int i=0; i<n; i++){
		max_till += ar[i];
		if(max_till > max_total){
			max_total= max_till;
			start= s;
			end= i;
		}
		if(max_till< 0){
			max_till= 0;
			s= i+1;
		};
	}
	cout<<max_total<<endl<<start<<" "<<end;
}
