#include<iostream>
#include<vector>
using namespace std;

int recursiveFactorial(int n){
	if(n==0) return 1;
	return n * recursiveFactorial(n-1);
}

void generateFactorial(int n, vector<int> &vi){
	for(int i= vi.size(); i<=n; i++){
		int fact=1;
		for(int j=1; j<=i; j++){
			fact*= j;
		}
		vi.push_back(fact);
	}
}
//2  3   5   7  11
//3, 8, 18, 32, 60 -- >  
//1  2   3   4   5 
int memFactorial(int n, vector<int> &viT){
	if(n==0) return 1;
	if(n<=viT.size()) return viT[n];
	else{
		cout<<"N: "<<n<<endl;
		cout<<viT[viT.size()]<<endl;
		int value=  n * memFactorial(n-1,viT);
		viT.push_back(value);
		cout<<"Value: "<<value<<endl;
	}
}

int main(){
	vector<int> vi;
	vector<int> viT;
	int n;
	cout<<"Enter a number: ";
	cin>>n;
	cout<<"Recursion Ouput: "<<recursiveFactorial(n)<<endl;
	vi.push_back(1);
	cout<<"Tabular Output: ";
	if(n<vi.size()) cout<<vi[n-1]<<endl;
	else{
		generateFactorial(n, vi);
		cout<<vi[n]<<endl;
	}
	cout<<"Memorizing Output: "<<memFactorial(n, viT)<<endl;
	
	return 0;
}
