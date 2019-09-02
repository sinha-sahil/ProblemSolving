#include<iostream>
#include<vector>
using namespace std;

vector<string> table{"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};

void printer(vector<int>& arr, int cd, string output, int n)
{
	if(n==cd){
		cout<<output<<" ";
		return;
	}
	string value= table[arr[cd]];
	for(int i=0; i< value.size(); i++){
		output[cd]= table[arr[cd]][i];
		printer(arr, cd+1, output, n);
		if(arr[cd]==0 or arr[cd]==1) return;
	}
}


int main(){
	vector<int> arr{2,3,4, 5,6};
	string output(arr.size(),' ');
	printer(arr, 0, output, arr.size());
}
