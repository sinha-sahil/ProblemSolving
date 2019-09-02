#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string stri) {
    vector<int> result;
    stringstream val(stri);
    int a;
    char ch;
    int lastC= stri.rfind(",");
    string lastValue= stri.substr(lastC+1, stri.length()-1);
    int lVal= stoi(lastValue);
    for(int i=0; i<stri.length(); i++){
    	val>>a>>ch;
    	result.push_back(a);
    	if(a==lVal) break;
	}
//	cout<<lastValue<<" "<<lVal<<endl;
	return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    return 0;
}
