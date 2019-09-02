#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool primeTest(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) return false;
	}
	return true;
}



int main(){

}
