// C++ implementation of the approach 
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std; 

// Function to find elements of vector 
void Print(vector<int>& ans) 
{ 
	for (auto i : ans) 
		cout << i << " "; 
} 

// Function to find the lexicographically largest 
// permutation that satisfies the given condition 
void Permutation(int a[], int n) 
{ 
	int flag = 0, pos; 

	// To store the required ans 
	vector<int> ans; 

	// Sort the array 
	sort(a, a + n); 

	for (int i = 2; i < n; i++) { 

		// If need to make arranagement 
		if (a[i] != a[i - 1] + __gcd(a[i - 1], a[i - 2])) { 
			flag = 1; 
			pos = i; 
			break; 
		} 
	} 

	// If possible then check for lexographically 
	// larger permutation (if any possible) 
	if (flag == 0) { 

		// If larger arrangement is possible 
		if (a[1] == a[0] + __gcd(a[0], a[n - 1])) { 
			ans.push_back(a[n - 1]); 
			for (int i = 0; i < n - 1; i++) 
				ans.push_back(a[i]); 

			Print(ans); 
			return; 
		} 

		// If no other arrangement is possible 
		else { 
			for (int i = 0; i < n; i++) 
				ans.push_back(a[i]); 

			Print(ans); 
			return; 
		} 
	} 

	// Need to re-arrange the array 
	else { 

		// If possible, place at first position 
		if (a[1] == a[0] + __gcd(a[pos], a[0])) { 
			flag = 0; 
			for (int i = n - 1; i > pos + 2; i--) { 

				// If even after one arrangement its impossible 
				// to get the required array 
				if (a[i] != a[i - 1] + __gcd(a[i - 1], a[i - 2])) { 
					flag = 1; 
					break; 
				} 
			} 

			if (flag == 0 and pos < n - 1) { 

				// If it is not possible to get 
				// the required array 
				if (a[pos + 1] 
					!= a[pos - 1] + __gcd(a[pos - 1], a[pos - 2])) 
					flag = 1; 
			} 

			if (flag == 0 and pos < n - 2) { 

				// If it is not possible to get 
				// the required array 
				if (a[pos + 2] 
					!= a[pos + 1] + __gcd(a[pos - 1], a[pos + 1])) 
					flag = 1; 
			} 

			// If it is possible to get the answer 
			if (flag == 0) { 
				ans.push_back(a[pos]); 
				for (int i = 0; i < n; i++) 
					if (i != pos) 
						ans.push_back(a[i]); 

				Print(ans); 
				return; 
			} 
		} 
	} 

	ans.push_back(-1); 
	Print(ans); 
} 

// Driver code 
int main() 
{ 
	int a[] = { 4, 6, 2, 8, 8 }; 
	int n = sizeof(a) / sizeof(a[0]); 

	Permutation(a, n); 

	return 0; 
} 
