#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n; cin>>n;
	int sum=0;
	vector<int> part1;
	vector<int> part2;
	int* ar= new int[n];
	for(int i=0; i<n; i++){
		cin>>ar[i];
		sum+= ar[i];
	}
	int sum2= sum;
	sum= sum/2;
	if(sum2%2!=0) cout<<"Not_Possible"<<endl;
	else{
		int currentSum=0;
		for(int i=0; i<n; i++){
			int testSum= currentSum+ ar[i];
			if(testSum<sum || testSum== sum){
				part1.push_back(ar[i]);
				currentSum=testSum;
			}else{
				part2.push_back(ar[i]);
			}
		}
	}
	cout<<"Part1: ";
	for(auto a: part1) cout<<a<<" ";
	cout<<endl;
	cout<<"Part2: ";
	for(auto b: part2) cout<<b<<" ";
}
