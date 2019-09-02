#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
	map<string, int> collection;
	string x; int y;
	cin>>x>>y;
	int test= collection["sahil"];
	collection.insert(make_pair(x,y));
	cout<<collection[x];
}
