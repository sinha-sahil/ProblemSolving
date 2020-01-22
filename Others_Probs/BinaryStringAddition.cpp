#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string binSum(string s1, string s2){
    reverse(begin(s1), end(s1));
    reverse(begin(s2), end(s2));
    string output="";
    int firstIndex = 0;
    int secondIndex = 0;
    int carry= 0;
    while(firstIndex<s1.size() or secondIndex<s2.size()){
        if(firstIndex<s1.size() && secondIndex<s2.size()){
            int n1 = static_cast<int>(s1[firstIndex]) - 48;
            int n2= static_cast<int>(s2[secondIndex]) - 48;
            int sValue = n1+n2+carry;
            if(sValue == 0) {output+= to_string(0); carry =0;}
            else if(sValue == 1) {output += to_string(1); carry=0;}
            else if(sValue ==2) { output += to_string(0); carry= 1;}
            else if(sValue==3) { output += to_string(1); carry=1;}
            firstIndex++; secondIndex++;
        }
        else if(firstIndex < s1.size()){
            int n1 = static_cast<int>(s1[firstIndex]) - 48;
            int sValue = n1+ carry;
            if(sValue  == 0) {output+= to_string(0); carry =0; }
            else if(sValue == 1) { output+= to_string(1); carry= 0;}
            else if(sValue == 2) { output += to_string(2); carry = 1; }
            firstIndex++;
        }
        else if(secondIndex < s2.size()){
            int n1 = static_cast<int>(s2[secondIndex]) - 48;
            int sValue = n1+ carry;
            if(sValue  == 0) {output+= to_string(0); carry =0; }
            else if(sValue == 1) { output+= to_string(1); carry= 0;}
            else if(sValue == 2) { output += to_string(2); carry = 1; }
            secondIndex++;
        }
    }
    if(carry) output+= to_string(1);
    reverse(begin(output), end(output));
    return output;
}

int main(){
    string input1;
    string input2;
    cin>>input1>>input2;
    cout<<binSum(input1, input2);
}