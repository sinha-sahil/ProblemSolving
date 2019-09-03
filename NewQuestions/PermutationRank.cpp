#include<iostream>
#include<vector>
using namespace std;

int getFactorial(int number, int mod){
    if(number == 0 or number == 1) return 1;
    //return number*getFactorial(number-1, mod);
    return ((number%mod) * (getFactorial(number-1, mod)%mod))% mod;
}

void genTable(vector<int>& vi, string input){
    for(char i: input){
        int index= static_cast<int>(i);
        vi[index]++;
    }
    for(int i= 1; i<vi.size(); i++){
        vi[i] += vi[i-1];
    }
}

void updateTable(vector<int>& vi, char i){
    int index = static_cast<int>(i);
    for(int j = index; j<vi.size(); j++){
        vi[j]--;
    }
}

int findRank(string input) {
    int mod = 1000003;
    int n= input.size();
    int factorial = getFactorial(input.size(), mod);
    long long int answer = 1;
    vector<int> vi(255,0);
    genTable(vi, input);
    for(int i=0; i<input.size(); i++){
        int cLeft = n-i;
        int cMul = factorial/cLeft;
        factorial = cMul;
        int fi = static_cast<int>(input[i]);
        cout<<vi[fi-1]<<" * "<<cMul<<endl;
        answer += vi[fi-1] * cMul;   
        updateTable(vi, input[i]);     
    }
    return answer%mod;
}


int main(){
    string input;
    input = "zyxwvutsrqponmlkjihgfedcba";
    // cin>>input;
    int mod = 1000003;
    int fact= getFactorial(26, mod);
    cout<<fact<<" "<<fact/26<<endl;
    cout<<findRank(input);
}
// 395916

//
 // -- Solution 
#include<iostream>
#include<vector>
using namespace std;

long long int fact[100000];
const int p = 1000003;
void fac(){
    fact[0] = 1;
    for(int i=1;i<=100000;i++)
        fact[i] = (1LL * fact[i-1] * i)%p;
}


void genTable(vector<int>& vi, string input){ 
    for(char i: input){
        int index= static_cast<int>(i);
        vi[index]++;
    }
    for(int i= 1; i<vi.size(); i++){
        vi[i] += vi[i-1];
    }
}

void updateTable(vector<int>& vi, char i){
    int index = static_cast<int>(i);
    for(int j = index; j<vi.size(); j++){
        vi[j]--;
    }
}

int findRank(string input) {
    int mod = 1000003;
    int n= input.size();
    fac();
    long long int answer = 1;
    vector<int> vi(255,0);
    genTable(vi, input);
    for(int i=0; i<input.size(); i++){
        int fi = static_cast<int>(input[i]);
        //cout<<vi[fi-1]<<" * "<<cMul<<endl;
        answer += (vi[fi-1] * fact[n-i-1])%mod;   
        updateTable(vi, input[i]);     
    }
    return answer%mod;
}


int main(){
    string input;
    input = "cab";
    // cin>>input;
    int mod = 1000003;
    // int fact= getFactorial(26, mod);
    // cout<<fact<<" "<<fact/26<<endl;
    cout<<findRank(input);
}
// 395916