#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int max_activity(vector<pair<int, int>> vi, int n){
	int j=0, total=0;
	for(int i=1; i<n; i++){
		if(vi[i].first >= vi[j].second){
			j=i;
			total++;
		}
	}
	return total+1;
}

int main(){
	vector<pair<int, int>> activity;
	cout<<"Activity Count: ";
	int n; cin>>n;
	int start, end;
	cout<<"Start and End Time: "<<endl;
	for(int i=0; i<n; i++){
		cin>>start>>end;
		activity.push_back(make_pair(start, end));
	}
	sort(activity.begin(), activity.end(), []( pair<int, int> one, pair<int, int> two){
		if(one.second< two.second) return true;
		return false;
	});
	cout<<endl<<"Jobs "<<endl;
	cout<<"Start\tEnd"<<endl;
	for(auto a: activity){
		cout<<a.first<<"\t"<<a.second<<endl;
	}
	cout<<endl<<"Total Time: "<< max_activity(activity, n);
}
