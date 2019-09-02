#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n; cin>>n;
	int* arr= new int[n];
	int* dep= new int[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	for(int j=0; j<n; j++) cin>>dep[j];
	sort(arr, arr+n);
	sort(dep, dep+n);
	int max_plat= 0;
	int current= 0;
	int index1=0, index2=0;
	while(index1<n and index2<n){
		if(arr[index1]<=dep[index2]){
			current++;
			index1++;
		}
		else{
			current--;
			index2++;
		}
		max_plat= max(max_plat, current);
	}
	cout<<max_plat<<endl;
}
