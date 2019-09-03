#include<iostream>
#include<vector>
using namespace std;

void printvec(vector<int> vi){
    for(auto i: vi){
        cout<<i<<" ";
    }
    cout<<endl;
}

int mod = 1000003;

vector<int> genFact(int n){
    vector<int> vi(n+1, 1);
    for(int i=1; i<=n; i++){
        vi[i] = ((i%mod) * (vi[i-1]%mod)) % mod;
    }
    return vi;
}

vector<int> getFreq(string input){
    vector<int> vi(255, 0);
    for(int i=0; i<input.size(); i++){
        vi[static_cast<int>(input[i])]++;
    }
    return vi;
}

vector<int> cumSum(vector<int> vi){
    for(int i=1; i<255; i++){
        vi[i] += vi[i-1];
    }
    return vi;
}

int getPower(int a, int b){
    if(b==0) return 1;
    if(b%2 ==0 ) return getPower(a*a%mod, b/2)%mod;
    return (a%mod * getPower(a*a%mod, b/2)%mod)%mod;
}

int getInverse(int num){
    return getPower(num, mod-2);
}

int getRank(string input){
    vector<int> fact = genFact(input.size());
    vector<int> freq = getFreq(input);
    // printvec(freq);
    vector<int> csum = cumSum(freq);
    int n = input.size();
    int answer = 1;
    for(int i=0; i<input.size(); i++){
        int asc = static_cast<int>(input[i]);
        int count = csum[asc-1];
        int div = 1;
        for(int j= 0; j< 255; j++){
            cout<<fact[freq[j]]<<" ";
            div = ((div%mod) * (fact[freq[j]]%mod))%mod;
        }
        long long int inv = getInverse(div)%mod;
        // cout<<count<<" "<<fact[n-i-1]<<" "<<div<<" "<<inv<<endl;
        answer = ((answer%mod) + ((((count%mod) * (fact[n-i-1]%mod))%mod) * (inv%mod ))%mod)%mod;

    }
    return answer;
}

int main(){
    string input;
    cin>>input;
    cout<<getRank(input);
}