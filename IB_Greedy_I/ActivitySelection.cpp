#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

void print(vector<pair<int, int>> vi){
    for(auto i: vi){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<"---------------------\n";
}

bool compFunc(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int solve(vector<int> &A, vector<int> &B) {
    vector<pair<int, int>> vi;
    for(int i=0; i<A.size(); i++){
        vi.push_back(make_pair(A[i], B[i]));
    }
    // print(vi);
    sort(begin(vi), end(vi), compFunc);

    int index = 0;
    int jobsDone = 1;
    
    for(int i= 1; i<vi.size(); i++){
        if(vi[i].first >= vi[index].second){
            // cout<<"Count@ "<<vi[i].first<<"-"<<vi[i].second<<"\n";
            jobsDone++;
            index = i;
        }
        else continue;
    }
    
    return jobsDone;
    
}


int main(){
    vector<int> A { 17, 8, 14, 24, 10, 8, 1, 30 };
    vector<int> B { 18, 45, 24, 27, 18, 10, 38, 35 };
    cout<<solve(A, B);
    return 0;
}