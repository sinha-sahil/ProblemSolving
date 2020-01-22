#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    vector<int> vi{11,2,3,11,4,5,6, 11, 11, 9 , 6, 12};
    sort(begin(vi), end(vi));
    auto itr = unique(begin(vi), end(vi));
    for(auto i = itr; i < vi.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    for(auto i = itr; i>= vi.begin(); i--){
        cout<<*i<<" ";
    }

    return 0;
}