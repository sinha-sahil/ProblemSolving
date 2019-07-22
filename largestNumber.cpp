#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> input(){
	int n;
	cin>>n;
	vector<int> vi(n);
	for(int i=0; i<n; i++) cin>>vi[i];
	return vi;
}

string largestNumber(vector<int> vi){
	string output = "";
	if(vi.size()==0) return output;

	sort(begin(vi), end(vi), [](int a, int b){

	});


	return output;
}

int main(){
	vector<int> vi;
	vi = input();
	cout<<largestNumber(vi);
}

5 4 3 2 1
--
40 5 4 3 2 1
540321

3, 30, 34, 5, 9
9 5 34 3 30 
9534303

54 546 548 60

--
54546 and 54654 
0

--

54546
54654

60 54 546 548
6054854654




60 54 
