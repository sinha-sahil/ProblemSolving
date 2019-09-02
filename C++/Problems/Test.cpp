#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<vector<int>> vj;
	int n, q;
	cin>>n>>q;
	for(int i=0; i<n; i++){
		int k; cin>>k;
		vector<int> vi;
		for(int j=0; j<k; j++){
			int value; cin>>value;
			vi.push_back(value);
		}
		vj.push_back(vi);
		vi.clear();
	}
	for(int r=0; r<q; r++){
		int i, j;
		cin>>i>>j;
		cout<<vj[i][j];
	}
}
