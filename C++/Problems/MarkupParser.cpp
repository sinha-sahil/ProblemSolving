#include<iostream>
#include<string>
using namespace std;

int main(){
	string code;
	int n, q;
	cin>>n>>q;
	for(int i=0; i<=n; i++){
		string input;
		getline(cin, input);
		code+= " "+input;
	}
	
	for(int r=0; r<q; r++){
		string query;
		cin>>query;
		int tilde= query.rfind("~");
		int lastDot= query.rfind(".");
		if(tilde==-1){
				cout<<"Not Found!"<<endl;	
		}
		else{
			string tagName;
			if(lastDot!=-1){
				tagName= query.substr(lastDot+1, tilde- lastDot-1);
			}
			else{
				tagName= query.substr(0,tilde);
			}
			string attribute= query.substr(tilde+1, tilde+1+tagName.length());
			int tagStart= code.find(tagName);
			if(tagStart !=-1){
				int endAngle= tagStart;
				int attribIndex =0;
				int matchLength= 0;
				string value="";
				bool first= false;
				bool second= false;
				bool run= false;
				bool start= false;
				while(static_cast<int>(code[endAngle]) != 62){
					if(attribute[attribIndex] == code[endAngle] && !run){
						matchLength++;
						attribIndex++;
					} else if(!run){
						matchLength=0; 
						attribIndex=0;
					}
					if(matchLength == attribute.length()){
						run = true;
					}
					if(run){
						if(static_cast<int>(code[endAngle])== 34 && !first){
							first = true;
						} else if(static_cast<int>(code[endAngle])== 34 && !second){
							second = true;
						}
						if(first && !second){
							value += code[endAngle];
						}
					}
					endAngle++;
				}
				if(run)
				cout<<value.substr(1, value.length()-1);
				else cout<<"Not Found!";
				cout<<endl;
			}
			else{
				cout<<"Not Found!"<<endl;
			}
		}
		query.clear();
	}

}
