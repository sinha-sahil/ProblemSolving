#include<iostream>
#include<vector>
using namespace std;

struct fishData{
    int size; 
    int eatFactor;
};

int main(){
    int t; cin>>t;
    for(int i=0; i<t; i++){
        int n; cin>>n;
        int maxSize=0;
        fishData collection[n];
        for(int k=0; k<n; k++){
            cin>>collection[k].size;   
            cin>>collection[k].eatFactor;
        }
        for(int r=0; r<n; r++){
            vector<fishData> allowed;
            for(int z=0; z<n; z++){
            	cout<<"Item: "<<z+1<<endl;
                if(collection[r].size > collection[z].eatFactor && collection[r].eatFactor < collection[z].size){
                    allowed.push_back(collection[z]);
                    cout<<"Item: "<<z+1<<" Allowed"<<endl;
                }
            }
            int newSize= allowed.size();
            if(newSize> maxSize){
                maxSize= newSize;
                cout<<"New Max: "<<newSize<<endl;
            }
            allowed.clear();
        }
        cout<<maxSize<<endl;
    }
}

