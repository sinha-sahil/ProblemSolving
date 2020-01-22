#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

bool isValid(int ascii){
    if((ascii >47 and ascii < 58) or (ascii >64 and ascii <91) or (ascii >96 and ascii <123)) return true;
    return false;
}


bool checkPalindrome(string input){
    string check= "";
    for(int i=0; i<input.length(); i++){
        int ascii= static_cast<int>(input[i]);
        if(isValid(ascii)) check += tolower(input[i]);
    }
    string temp = check;
    reverse(begin(check), end(check));
    cout<<check<<" "<<temp<<endl;
    return (temp == check);
}


// vector<string> jsonify(string input){
//     vector<string> result;
//     int tabCount = 0;
//     for(int i=0; i< input.length(); i++){
//         if(input[i] == '[' or input[i] == '{') tabCount++;
//         else if(input[i] == ']' or input[i] == ']') tabCount--;
//         else{

//         }
//     }
//     return result;
// }


string reverseString(string input){
    string output= "";
    input[0] = ' ';
    input[input.length()-1] = ' ';
    stringstream sStream(input);
    string temp="";
    while(sStream >> temp){
        output = temp+ " "+ output ;
    }
    output= '"'+ output;
    output[output.size()-1] = '"';
    return output;
}

int lengthOfLast(string input){
    int result;
    stringstream sstr(input);
    string temp;
    while(sstr >> temp) result = temp.length();
    return result;
}

void generate(vector<string>& data){
    string addition="";
    string last= data[data.size()-1];
    for(int i=0; i<last.size(); i++){
        int count= 0;
        char key= last[i];
        while(key == last[i]){
            count++;
            i++;
        }
        i--;
        addition += to_string(count) + key;
    }
    data.push_back(addition);
}


string nextString(string input){
   string output = "";
   for(int i=0; i<input.size(); i++){
       char key = input[i];
       int count = 0;
       while(input[i] == key){
           i++; count++;
       }
       i--;
       output+= to_string(count)+ key;
   }
   return output;
}

string getLast(int n){
    string last = "1";
    int curr= 1;
    while(curr!= n){
        last= nextString(last);
        curr++;
    }
    return last;
}


string getPrefix(vector<string> input){
    if(input.size()==0) return "";
    string output = input[0];
    for(int i=1; i<input.size(); i++){
        string current= input[i];
        string temp= "";
        int oIndex= 0; int cIndex = 0;
        while(oIndex < output.size() && cIndex < current.size()){
            if(current[cIndex] == output[oIndex]){ 
                temp+= current[cIndex];
                cIndex++; oIndex++;
            }
            else break;
        }
        output= temp;
    }
    return output;
}

bool isValidDigit(int ascii){
    if((ascii>47 and ascii<57) or (ascii == 101) ) return true;
    return false;
}

bool isNumber(string input){
    bool e= false;
    int eIndex=-1;
    bool dot= false;
    for(int i=0; i<input.size(); i++){
        int ascii = static_cast<int>(input[i]);
        if(input[i]=='-'){
            if(i==0) continue;
            else return false;
        }
        else if(input[i]=='.'){
            if(not dot) dot= true;
            else if(dot) return false;
            if(i== input.size()-1 ) return false;
            else continue;
        }
        else if(isValidDigit(ascii)){
            if(input[i]== 'e'){
                if(not e) e= true;
                else if(e) return false;
                eIndex= i;
            }
        }
        else if(!isValidDigit(ascii)) return false;
    }
    if(eIndex ==0 or eIndex==input.size()-1) return false;
    return true;
}

int main(){
    // string input;
    // getline(cin, input);
  //  cout<<checkPalindrome(input);
  //cout<<reverseString(input);
  //cout<<lengthOfLast(input);
    cout<<isNumber("121.2ee10");
}