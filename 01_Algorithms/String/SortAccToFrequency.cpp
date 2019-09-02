// given sequence , sort according to the frequency.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> dCol;
	vector<int> cCount;
	int data;
	for(int i=0; i<n; i++){
		cin>>data;
		dCol.push_back(data);
	}
	sort(begin(dCol), end(dCol));
	int total=0;
	int i=0, j=0;
	//error in looping.
	while(total!= n){
		cout<<"Came: i: "<<i<<" j:"<<j<<endl;
		while(dCol[i]== dCol[j]){
			j++;
		}
		cCount.push_back(j-i+1);
		total+= j-i+1;
		i= j+1;
	}
	for(auto i: cCount){
		cout<<i<<" ";
	}	
}
