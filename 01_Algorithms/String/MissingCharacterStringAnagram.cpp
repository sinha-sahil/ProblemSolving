#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	string s1,s2;
	cout<<"String 1 and 2: "; cin>>s1;
	cin.ignore();
	cin>>s2;
	vector<int> vi(256, 0);
	vector<int> vj(256, 0);
	for(int i=0; i<s1.size(); i++){
		vi[static_cast<int>(s1[i])]++;
	}
	for(int j=0; j<s2.size(); j++){
		vj[static_cast<int>(s2[j])]++;
	}
	int count=0;
	for(int j=0; j<vi.size(); j++){
		count+= abs(vi[j]- vj[j]);
	}
	cout<<"Count: "<<count;
}
