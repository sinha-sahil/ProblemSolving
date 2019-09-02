#include<iostream>

using namespace std;
//Shift all zeros to last

int main() {
	int n; cin >> n;
	int *ar = new int[n];
	for (int i = 0; i < n; i++) cin>>ar[i];
	int zeroCount = 0;
	int lastIndex = n-1;
	for (int j = 0; j <= lastIndex; j++) {
		if (ar[j] == 0) {
			for(int k=j; k<=lastIndex; k++){
				ar[k]= ar[k+1];
			}
			ar[lastIndex] = 0;
			lastIndex--;
			j-=1;
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) cout<< ar[i]<<" ";
}
