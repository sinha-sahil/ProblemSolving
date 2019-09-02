#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	cout<<s.substr(0,4);
	cout<<s[4];
}
