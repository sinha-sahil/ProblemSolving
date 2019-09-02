#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;
	cin>>a;
	for(int i=0; i<a.length(); i++){
		for(int j=0; j<a.length()-i-1; j++){
			if(a[j]>a[j+1]){
				char temp= a[j];
				a[j]= a[j+1];
				a[j+1]= temp;
			}
		}
	}
	cout<<a;
	return 0;
}
