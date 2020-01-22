#include<iostream>
#include<string>

using namespace std;


void permutation(string s, string prefix){
	if(not s.length()) cout<<prefix<<endl;
	for(int i=0; i<s.length(); i++){
		char c = s[i];
		string rem = s.substr(0, i) + s.substr(i+1, s.length());
		permutation(rem, prefix+c);
	}
}

// int n = s.length();
// ||
// \/

void repeatPerms(vector<int> freq, string prefix){
	if(prefix.size() == n) cout<<prefix<<endl;
	for(int i=0; i<26; i++){
		if(freq[i] == 0) continue;
		char c = static_cast<char>(i+97);
		freq[i]--;
		repeatPerms(freq, prefix+ c);
		freq[i]++;
	}
}

int main(){
	permutation("abc", "");
}