#include<iostream>
#include<string>
using namespace std;

void parseQuery(String q, String const& code){
	int dotIndex= q.find(".");
	int tildeIndex= q.find("~");
	
}

int main(){
	int n; cin>>n;
	int q; cin>>q;
	string code;
	for(int i=0; i<=n; i++){
		string input;
		getline(cin, input);
		code+= input+" ";
	}
	//cout<<endl<<code<<endl;
	for(int i=0; i<q; i++){
		string query;
		cin>>query;
		parseQuery(query, code);
	}
}
