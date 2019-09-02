#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// lemoid conjecture
// p smooth numbers
// ugly number
// beautiful numbers
// rough numbers

// tuesday ca: every thing except the greedy algorithm

class job{
	public:
	int id;
	int time;
	int loss;
	int lt;
};

int main(){
	int n =5;
	job jobs[5];
	cout<<"Enter 5 Job Time and Loss\n";
	for(int i=0; i<5; i++){
		jobs[i].id = i+1;
		cout<<"Time: "; cin>>jobs[i].time;
		cout<<"Loss: "; cin>>jobs[i].loss;
		jobs[i].lt= jobs[i].loss/ jobs[i].time;
	}
	sort(begin(jobs), end(jobs), [](job const& j1, job const& j2){
	//	if(j1.lt > j2.lt) return true;
	//	return false;
		if(j1.loss * j2.time > j2.loss * j1.time) return true;
		return false;
	});
	cout<<"Ouput:"<<endl;
	for(int i=0; i<5; i++){
		cout<<"Job: "<<jobs[i].id<<endl;
	}
	return 0;
}
