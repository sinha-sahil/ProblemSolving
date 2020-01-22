#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void swap(int& a, int& b){
	a = a + b;
	b = a - b;
	a = a - b;
}

vector<int> getWave(vector<int> vi){
	sort(begin(vi), end(vi));
	for(int i=0; i<vi.size(); i+=2){
		if(i+1 > vi.size()-1) continue;
		swap(vi[i], vi[i+1]);
	}
	return vi;
}


int main(){
    vector<int> vi = {1,2,3,4,5,6};
    vi = getWave(vi);
    for(auto i: vi) cout<<i<<" ";
    return 0;
}