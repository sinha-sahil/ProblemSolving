#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	string s1, s2;
	cout<<"String 1 and 2: ";
	cin>>s1>>s2;
	//method 1
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	cout<<"Method 1: ";
	if(s1== s2) cout<<"Yes"<<endl; else cout<<"No"<<endl;
	//method 2
	vector<int> vi(256, 0);
	vector<int> vj(256, 0);
	for(int i=0; i<s1.size(); i++){
		vi[static_cast<int>(s1[i])]++;
		vj[static_cast<int>(s2[i])]++;
	}
	bool findStat= true;
	for(int i=0; i<vi.size(); i++){
		if(vi[i]!= vj[i]) findStat= false;
	}
	cout<<"Method 2: ";
	if(findStat) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
}
