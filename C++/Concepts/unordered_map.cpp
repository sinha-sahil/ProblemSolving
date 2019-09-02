#include<unordered_map>
#include<iostream>
using namespace std;

int main(){
	unordered_map<int, int> hash;
	hash[101] =1;
	cout<<hash[101];
	if(hash[101]) cout<<"Yes"<<endl;
	if(hash[102]) cout<<"No";
	hash[102]++;
	cout<<hash[102];
}


