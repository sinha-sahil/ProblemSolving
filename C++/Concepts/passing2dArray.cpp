
#include <iostream>
using namespace std;
int diagonalSum(int** arr, int N){
    int sum = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
        	cout<<arr[i][j]<<" ";
            if(i==j)
            sum+= arr[i][j];
        }
    }
    return sum;
    
}
//Initial Template for C++

//Position this line where user code will be pasted.
// Driver code
int main() {
	
	int testcase;
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
        
        // Declaring pointer to pointer
        // to create 2D array
        int **arr;
        arr = new int*[N];
        
        // For every i, create a dynamic array
        // and take input
        for(int i = 0;i<N;i++){
            arr[i] = new int[N];
            for(int j = 0;j<N;j++){
                cin >> arr[i][j];
            }
        }
        
         cout << diagonalSum(arr, N) << endl;
	    
	}
	
	return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/*Function to find diagonal sum
* N : size of array
* arr : input array
* Note : You have to mention argument also
*/

