#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> vi{1,2,3,4,5};
	int ans=0;
	for(auto i: vi){
		ans= ans xor i;
	}
	vector<int> vj{1,2,3,5};
	for(auto i: vj){
		ans= ans xor i;
	}
	cout<<ans;
}
