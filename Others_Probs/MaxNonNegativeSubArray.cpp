#include<iostream>
#include<vector>
using namespace std;

vector<int> input(){
	int n;
	cin>>n;
	vector<int> vi(n);
	for(int i=0; i<n; i++) cin>>vi[i];
	return vi;
}

vector<int> findMaxNon(vector<int> vi){
	int start= -1;
	int end = -1;
	int maxSum = INT_MIN;
	int cStart = -1;
	int cEnd= -1;
	int cSum =0;
	int n= vi.size();

	for(int i=0; i<n; i++){
		if(vi[i] >= 0){
			if(cStart == -1 ) cStart = i;
			if(cEnd == -1) cEnd = i;
			else if(cEnd != -1) cEnd++;
			cSum += vi[i];
		}
		else if(vi[i]<0){
			if(cSum > maxSum){ 
				maxSum = cSum;
				start= cStart;
				end = cEnd;
			}
			else if (cSum == maxSum){
				int l1= end - start;
				int l2= cEnd - cStart;
				if(l1 > l2) continue;
				else if(l1 < l2){
					start= cStart;
					end = cEnd;
				}
			}
			cStart = -1;
			cEnd = -1;
			cSum = 0;
		}
	}

	vector<int> result;
	if(start == -1) return result;
	for(int i=start; i<= end; i++) result.push_back(vi[i]);
	return result;
}

int main(){
	vector<int> vi;
	vi = input();
	vi = findMaxNon(vi);
	for(auto i: vi) cout<<i<<" ";
}