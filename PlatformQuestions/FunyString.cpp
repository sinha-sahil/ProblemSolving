#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
    vector<int> vi;
    vector<int> vj;
    string ds, ds2;
    int n= s.size()-1;
    for(int i=0; i<s.size(); i++){
        vi.push_back(static_cast<int>(s[i]));
        vj.push_back(static_cast<int>(s[n-i]));
         if(i!=0){
             ds+= to_string(vi[i]- vi[i-1]);
             ds2+= to_string(vj[i]- vj[i-1]);
         }
    }
    if(ds==ds2) return "Funny";
    else return "Not Funny"; 
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

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

