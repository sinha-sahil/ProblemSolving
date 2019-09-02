#include<iostream>
#include<string>
using namespace std;

int main(){
	string s1; string s2;
	cin>>s1>>s2;
	int len= max(s1.length(), s2.length());
	int dtable[len][len];
	for(int i=0; i<len ; i++){
		for(int j=0; j<len; j++){
			if(i==0 && j==0) dtable[i][j]=0;
			else if(i==0){
				dtable[i][j]= j;
			} else if(j==0){
				dtable[i][j]=i;
			}
			else if(s1[i]== s2[j]){
				dtable[i][j]= dtable[i-1][j-1];
			} else{
				dtable[i][j]= min(dtable[i-1][j], dtable[i][j-1])+1;
			}
		}
	}
	cout<<dtable[s1.length()-1][s2.length()-1];
	
}
