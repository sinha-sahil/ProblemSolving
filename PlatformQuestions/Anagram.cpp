#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    if(s.size()%2!=0) return -1;
    else{
        int mid= s.size()/2;
        string s1= s.substr(0, mid);
        string s2= s.substr(mid);
        vector<int> s1Num(256,0);
        vector<int> s2Num(256,0);
        for(int i=0; i<s1.size(); i++) s1Num[static_cast<int>(s1[i])]++;
        for(int i=0; i<s2.size(); i++) s2Num[static_cast<int>(s2[i])]++;
        bool state= true;
        for(int i=0; i<s1Num.size(); i++){
            if(s1Num[i]!=s2Num[i]){
                state= false;
                break;
            }
        }   
        if(state) return 0;
        else{
            long long int count=0;
            for(int i=0;i<s1Num.size(); i++){
                if(s1Num[i]!= s2Num[i] && s2Num[i]!=0 && s1Num[i]==0)
                    count+=1;
            }
            return count;
        }
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        cout << result << "\n";
    }

    fout.close();

    return 0;
}

