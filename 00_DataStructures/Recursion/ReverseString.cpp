#include<iostream>
#include<vector>
using namespace std;

void revString(vector<char>& vi){
	if(vi.empty()) return;
	char x= vi[0];
	vi.erase(vi.begin());
	revString(vi);
	vi.push_back(x);
}

int main(){
	vector<char> vi{'a','e','i','o','u'};
	revString(vi);
	for(auto i: vi){
		cout<<i<<" ";
	}
}
