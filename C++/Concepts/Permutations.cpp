#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string s="1234";
	do{
		cout<<s<<endl;
	}while(next_permutation(s.begin(), s.end()));
}

