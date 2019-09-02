#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	string code;
	int n; cin>>n;
	for(int i=0; i<=n; i++){
		getline(cin, code);
		code+=" ";
	}
	string query;
	cin>>query;
	int dot= query.find(".");
	int start=0;
	string workCode= code;
	while(dot!=-1){
		cout<<query<<endl;
		string findString= query.substr(start, dot);
		cout<<findString<<endl;
		query= query.substr(dot+1, query.length());
		cout<<query<<endl;
		int sliceStart= workCode.find("<"+findString);
		int sliceEnd= workCode.find("</"+findString+">");
		cout<<sliceStart<<" "<<sliceEnd<<endl;
		if(sliceStart!=-1 && sliceEnd!=-1){
			workCode= workCode.substr(sliceStart, sliceEnd);
			dot= query.find(".");
		} else{
			cout<<"Not Found!"<<endl;
			break;
		}
	}
	cout<<workCode;
	return 0;
}
