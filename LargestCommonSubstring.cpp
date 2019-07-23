#include<iostream>
#include<vector>
using namespace std;

string findLargSubs(vector<string> vi){
    string minStr ="";
    for(auto i: vi){
        if(minStr =="") minStr = i;
        else{
            if(minStr.size() > i.size()) minStr = i;
        }
    }

    for(auto i: vi){
        string answer = "";
        int index = 0;
        for(int j=0; j<minStr.size(); j++){
            if(i[j] == minStr[index]){
                answer += minStr[index];
                index++;
            }
        }
        minStr = answer;
    }

    return minStr;
}

int main(){
    vector<string> vi{"abab", "ab", "abcd"};
    cout<<findLargSubs(vi);

}