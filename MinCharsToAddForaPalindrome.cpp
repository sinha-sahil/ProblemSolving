
void fillLps(vector<int>& lps, string input){
    int i=0, j = i+1;
    while(j< input.size()){
        if(input[i] == input[j]){
            int iValue = i;
            lps[j] = iValue + 1;
            i++; j++;
        }
        else {
            if(i == 0) j++;
            else{
                i = lps[i-1];
            }
        }
    }
}

int Solution::solve(string A) {
    string update = A;
    reverse(begin(update), end(update));
    string pre = A + '$' + update;
    vector<int> lps(pre.size(), 0);
    fillLps(lps, pre);
    return A.size() - lps[lps.size()-1];
}
