#include<iostream>
using namespace std;

int knapsack(int w[], int val[], int wt, int n){
	if(n==0 || wt==0) return 0;
	
	if(w[n-1]> wt){
		return knapsack(w, val, wt, n-1);
	}
	else return max(
		val[n-1]+ knapsack(w, val, wt- w[n-1], n-1),
		knapsack(w, val, wt, n-1)
	);
}


int main(){
 	int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    cout<<knapsack(wt, val, W, 3);
}
