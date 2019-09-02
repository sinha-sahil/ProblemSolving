#include<iostream>
#include<vector>
using namespace std;

// join n ropes

int minCoins(vector<int> vi, int value){
	int total=0; 
	while(value>0){
		int index= vi.size()-1;
		for(int i=0; i<vi.size(); i++){
			if(vi[i]>value){
				index= i-1;
				total++;
				break;
			}
			else if(vi[i]== value){
				index=i; total++;
				break;
			}
		}
		value= value-vi[index];
	}
	return total;
}

int main(){
	cout<<"Amount: ";
	int amount;
	cin>>amount;
	bool done= false;
	vector<int> denom{1, 2, 5, 10, 50, 100};
	cout<<minCoins(denom, amount);
	
}
