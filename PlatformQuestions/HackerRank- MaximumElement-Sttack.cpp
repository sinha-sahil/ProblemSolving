#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    vector<char> vs; 
    for(int i=0; i<s.size(); i++){
        if(vs[i]!='}' and vs[i]!=')' and vs[i]!=']'){
            vs.push_back(vs[i]);
        } else{
            char inp= vs[vs.size()-1];
            if(inp != vs[i]) return "NO";
            else vs.pop_back(); 
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

