#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n, a,b,k;
		cin>>n>>a>>b>>k;
		long long int c_a=0, c_b=0;
		for(long long int i=1; i<n; i++){
			if(i%a==0 and i%b==0){
				continue;
			}
			else if(i%a==0 and i%b!=0){
				c_a++;
			}
			else if(i%a!=0 and i%b==0){
				c_b++;
			}
		}
		int sum_value= c_a + c_b;
		if(sum_value >= k){
			cout<<"Win\n";
		}
		else cout<<"Lose\n";
	}
}
