#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	cin>>s;
	for(int i=0; i< s.size(); i++){
		if(i!= s.size()-1 && s[i]==s[i+1]){
			s.erase(s.begin()+i, s.begin()+i+2);
			i--;
		}
		cout<<s<<endl;
	}
}

