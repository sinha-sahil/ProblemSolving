#include<bits/stdc++.h>
using namespace std;

void getValues(vector<int> vi, int& x, int& y){
	int n= vi.size();
	int xor_value= 0;
	for(auto i: vi) xor_value = xor_value xor i;
	for(int i=1; i<=n; i++) xor_value = xor_value xor i;
	int set_bits= xor_value & ~(xor_value-1);
	x=0;
	y=0;
	for(int i=0; i<n; i++){
		if(vi[i] & set_bits){
			x= x xor vi[i];
		}
		else y= y xor vi[i];
	}
	for(int i=1; i<=n; i++){
		if(i & set_bits){
			x= x xor i;
		}
		else y= y xor i;
	}
}

int main(){
	vector<int> vi{1,2,2,3,5};
	int x, y;
	getValues(vi, x, y);
	cout<<x<<" "<<y;
}

