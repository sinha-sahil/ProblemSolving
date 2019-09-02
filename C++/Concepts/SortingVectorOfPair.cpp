#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	pair<int, int> ar[5];
	ar[0]= make_pair(2,1);
	ar[1]= make_pair(5,2);
	ar[2]= make_pair(3,3);
	ar[3]= make_pair(1,4);
	ar[4]= make_pair(4,5);	
	sort(ar, ar+5);
	for(int i=0; i<5; i++){
		cout<<"First: "<<ar[i].first<<" Second: "<<ar[i].second;
		cout<<endl;
	}
}
