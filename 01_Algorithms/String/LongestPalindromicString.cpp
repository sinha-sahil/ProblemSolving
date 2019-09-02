#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	string input;
	cin>>input;
	vector<int> vi(input.size(), 0);
	for(int i= 0; i< input.size(); i++){
		if(i==0 or i==input.size()-1){
			vi[i]=1;
		}
		else{
			cout<<"Came here"<<endl;
			int count=0;
			int left= i-1;
			int right= i+1;
			cout<<input[left]<<" "<<input[right]<<endl;
			while(input[left]==input[right] and left>=0 and right<input.size()){
				count++;
				left--;
				right++;
				cout<<input[left]<<" "<<input[right]<<endl;
			}
			vi[i]= count;
		}
	}
	cout<<*max_element(begin(vi), end(vi));
	
}
