#include<iostream>
#include<string>
using namespace std;

string summer(string s1, string s2){
	int carry=0;
	string sumValue="";
	if(s1.length() == s2.length()){
		for(int k= s1.length()-1; k>=0; k--){
		//	cout<<"Came Here"<<endl;
			int sU = static_cast<int>(s1[k])- static_cast<int>('0');
			int sD = static_cast<int>(s2[k])- static_cast<int>('0');
			if(carry==0){
				int out= sU+ sD;
				if(out>9){
					carry= out/10;
					out%= 10;
				}
				sumValue= to_string(out)+ sumValue;
			} else {
				int out= sU+ sD + carry;
				if(out>9){
					carry= out/10;
					out%= 10;
				} else{
					carry=0;
				}
				sumValue= to_string(out)+ sumValue;
			}
		}
		if(carry!=0){
			sumValue= to_string(carry)+ sumValue;
		}
	}
	else{
		string uS= s1.length() > s2.length() ? s1:s2;
		string lS= s1.length() < s2.length() ? s1:s2;
		int carry=0;
		int largeLast= s1.length()-1;
		for(int k= lS.length()-1; k>=0; k--){
			int sU= static_cast<int>(lS[k]) - static_cast<int>('0');
			int sL= static_cast<int>(uS[largeLast]) - static_cast<int>('0');
			if(carry==0){
				int out= sU+ sL;
				if(out>9){
					carry= out/10;
					out%=10;
				}
				sumValue= to_string(out)+ sumValue;
			} else{
				int out= sU+ sL+ carry;
				if(out>9){
					carry= out/10;
					out%=10;
				} else{
					carry=0;
				}
				sumValue= to_string(out)+sumValue;	
			}
			largeLast--;
		}
		for(int r= largeLast; r>=0; r--){
			int remain= static_cast<int>(uS[r])- static_cast<int>('0');
			if(carry!=0){
				int opt= remain + carry;
				if(opt>9){
					carry= opt/10;
					opt%=10;
				} else{
					carry=0;
				}
				sumValue = to_string(opt) + sumValue;
			} else{
				sumValue = to_string(remain)+ sumValue;
			}
		}
		if(carry!=0) sumValue= to_string(carry)+ sumValue;
	}
	return sumValue;
}

int main(){
	string a= "72767898";
	string b="676712";
	cout<<summer(a,b);
}
