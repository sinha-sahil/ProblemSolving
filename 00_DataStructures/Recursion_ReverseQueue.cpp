#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void stackPush(int n, queue<int>& qi, stack<int>& si){
//	cout<<"Stack: ";
	if(!qi.empty()){
		si.push(n);
		qi.pop();
		stackPush(qi.front(), qi, si);
		//cout<<"N: "<<n<<" Stack top: "<<si.top()<<" Queue front: "<<qi.front()<<endl;
	}
}

void pullBack(int n, queue<int>& qi, stack<int>& si){
	if(!si.empty()){
		qi.push(n);
		si.pop();
		pullBack(si.top(), qi, si);		
	}
} 
void revQ(queue<int>& Q);

int main(){
	queue<int> qi;
	stack<int> si;
	for(int i=0; i<10; i++) qi.push(i);
//	stackPush(qi.front(), qi, si);
//	pullBack(si.top(), qi, si); 
	revQ(qi);
	cout<<"Reverse Queue: ";
	while(!qi.empty()){
		cout<<qi.front()<<" ";
		qi.pop();
	}
}

//CA: 
//Arrays LL Stacks Queues

void revQ(queue<int>& Q){
	if(Q.size()==0){
		return;
	}
	int E= Q.front();
	Q.pop();
	revQ(Q);
	Q.push(E);
}
