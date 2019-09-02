#include<iostream>
#include<cmath>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int k; cin>>k;
        int* arr= new int[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        int loc;
        int low= 0;
        int high= n-1;
        while(low<=high){
            if(low==high){
               loc= low;
               break;
            }
            else if(high-low==1){
                int value= abs(arr[low]- k);
                int value2= abs(arr[high]-k);
                if(value < value2) loc= low;
                else loc= high;
                break;
            }
            else{
                int mid= low + (high- low)/2;
                int vm= abs(arr[mid]- k);
                int vl= abs(arr[mid-1]-k);
                int vr= abs(arr[mid+1]-k);
                if(vm < vr and vm < vl){
                    loc= mid;
                    break;
                }
                else if(vm == vr or vr<vm) low= mid+1;
                else if(vm == vl){
                    loc= mid;
                    break;
                }
                else if(vl< vm and vl<vr) high= mid-1;
             // else if(vr<vm and vr<vl) low = mid+1;
            }
        }
        cout<<arr[loc]<<"\n";
        
    }
	return 0;
}
