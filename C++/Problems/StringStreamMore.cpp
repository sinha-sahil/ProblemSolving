#include<bits/stdc++.h>
using namespace std;

int main(){
	string s="sahil,sinha,is,great,boy,and,i,like,to,talk,to,him";
	stringstream input(s);
	string output;
	string word;
	while(getline(input,word,',')){
		output+= " "+word;
	}
	cout<<output<<endl;
	cout<<s(0,string::npos);
	return 0;
}
