#include<iostream>
#include<cstring>
using namespace std;

char* function(char* string){
	int len= strlen(string);
	for(int k=0; k<len; k++){
		if(string[k]=='a' or string[k]=='e' or string[k]=='i' or string[k]=='o' or string[k]=='u'){
			for(int z=k; z<len-1; z++){
				string[k]= string[k+1];
			}
			len--;
			string[len]= NULL;
		}
		else{
			cout<<string[k]<<endl;
		}
	}
	return string;
} 

int main(){
	char* string= "hello";
	cout<<function(string);
}
