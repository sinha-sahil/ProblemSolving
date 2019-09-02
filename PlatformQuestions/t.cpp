#include<iostream>

using namespace std;

int main() {
	int n; cin >> n;
	int *ar = new int[n];
	for (int i = 0; i < n; i++) cin>>ar[i];
	int i = 0;
	int j = n-1;
	while(1)
	{
		if(ar[i] == 0 && ar[j]!=0)
		{
			ar[i] = ar[j];
			ar[j] = 0;
			i++;
			j--;
		}
		else
		{
			if(ar[j] == 0)
				j--;
			if(ar[i]!=0)
				i++;
		}
		if(i>j)
			break;
	}
	cout << endl;
	for (int i = 0; i < n; i++) cout<< ar[i]<<" ";
}
	
