#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int> vi{22,11,79, 33, 45};
	sort(begin(vi), end(vi), [](int a, int b){
		return a<b;
	});
	for(auto i: vi){
		cout<<i<<" ";
	}
	
}
