#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class item{
	public:
		int wt;
		int cost;
};

int main(){
	int n; cout<<"#Items: "; cin>>n;
	item* items= new item[n];
	for(int z=0; z<n; z++){
		cout<<"Weight: ";cin>>items[z].wt;
		cout<<"Price: ";cin>>items[z].cost;
		items[z].wC = items[z].wt/items[z].cost;
		cout<<endl;
	}
	sort(begin(items), end(items),[](item const& i, item const& j){
		if(i.wC > j.wC) return true;
		return false;
	});
	for(int i=0; i<n; i++){
		cout<<"wt: "<<items[i].wC<<endl;
	}
}
