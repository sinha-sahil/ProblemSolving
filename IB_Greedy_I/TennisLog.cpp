#include<iostream>
#include<vector>

using namespace std;


bool isValid(int cp1, int cp2, int result){
    return (result == cp1 || result == cp2);
}

void updateRes(int& cp1, int& cp2, int result){
    if(result == cp1) {
        cp2 = 6 - cp1 - cp2;
    }
    else if(result == cp2){
        cp1 = 6 -cp1 -cp2;
    }
}

string checkIfValidLog(int n, vector<int> logs){
    int cp1 = 1;
    int cp2 = 2;
    for(int i=0; i<logs.size(); i++){
        cout<<logs[i]<<" "<<cp1<<" "<<cp2<<endl;
        if(isValid(cp1, cp2, logs[i])){
            updateRes(cp1, cp2, logs[i]);
        }
        else return "No";
    }
    return "Yes";
}

int main(){
    vector<int> a{1,2};
    cout<<checkIfValidLog(2, a);

}