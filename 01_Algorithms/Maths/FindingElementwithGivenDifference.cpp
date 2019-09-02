//finding element with given difference.
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n; cin>>n;
	int ar[n];
	for(int i=0; i<n; i++) cin>>ar[i];
	sort(ar, ar+n);
	int diff; cin>>diff;
	int i=0, j=1;
	int count=0;
	bool found= false;
	while(j<n){
		int cdiff= ar[j]-ar[i];
		if(cdiff<diff){
			++j;
		}
		else if(cdiff> diff) ++i;
		else if(cdiff==diff) {
			found= true;
			count++;
			++j;
			i++;
		}	
	}
	if(!found) cout<<"Not Found";
	else{
		cout<<count<<endl;
	}
}
