#include<iostream>
#include<string>
using namespace std;

string value(string left, string right){
	if( left.size() ==1 && right.size()==1){
		int ls= stoi(left);
		int rs= stoi(right);
		return static_cast<string>(ls*rs);
	} else{
		continue;
	}
}

int main(){
	string test;
	cin>>test;
	cout<<test.size();
	cout<<endl<<test;
	cout<<endl<<value(test, test);
}
