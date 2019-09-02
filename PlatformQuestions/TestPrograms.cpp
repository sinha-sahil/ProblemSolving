#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	int n; cin>>n;
	string s; cin>>s;
	sort(s.begin(), s.end());
	int max=0;
	for(int i=0; i<s.length(); i++){
		int value= count(s.begin(), s.end(), s[i]);
		cout<<s<<endl;
		if(max< value){
			max= value;
			remove_copy (s.begin(),s.end(),s.begin(),s[i]);
		}
	
	}
	cout<<n-max<<endl;
}
