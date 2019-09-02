#include<iostream>
#include<cmath>
using namespace std;

int main(){
	cout<<"N: "; int n; cin>>n;
	cout<< "Nth Number: "<<n +  floor(0.5 + sqrt(n));
}
