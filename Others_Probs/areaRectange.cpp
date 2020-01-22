#include<iostream>
uisng namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
		int x1, y1, x2, y2;
		int a1, b1, a2, b2;
		cin>>a1>>b1>>a2>>b2;
		cin>>x1>>y1>>x2>>y2;
		long long int total_area = (abs(x1-x2)) * (abs(y1-y2));
		total_area += (abs(a1-a2)) * (abs(b1-b2));

		
	}
}