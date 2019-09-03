#include<iostream>
#include<stack>

using namespace std;

// , /, *, +, -, (, )

bool isChar(char i){
    if (i == '^' or i  == '/' or i == '*' or i == '+' or i == '-' or i == '(' or i == ')')
    return false;
    return true;
}

int getPower(char i){
    if (i == '(' or i == ')') return 4;
    if ( i ==  '^') return 3;
    if (i == '*' or i == '/') return 2;
    if (i == '+' or i == '-') return 1;
    return -1;
}

bool isGrt(char i , char j){
    int pi = getPower(i);
    int pj = getPower(j);
    if( i == '(' and j == ')') return true;
    else if(i == '(') return false;
    else if(pi >= pj) return true;
    return false;
}

string getPostFix(string input){
    stack<char> stk;
    string answer = "";

    for(int i=0; i<input.size(); i++){
        if(isChar(input[i])){
            answer += input[i];
        }
        else {
            if(stk.empty()){
                stk.push(input[i]);
            }
            else {
                if(input[i] == ')'){
                    while(not stk.empty() and stk.top() != '(' ){
                        answer += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                }
                else {  
                    while(not stk.empty() and isGrt(stk.top(), input[i])){
                        if(stk.top() != '(' and stk.top() != ')') answer += stk.top();
                        stk.pop();
                    }
                    stk.push(input[i]);
                }
            }

        }
    }
    while(not stk.empty()){
        answer += stk.top();
        stk.pop();
    }

    return answer;
}

int main(){
    string input;
    cin>>input;
    cout<<getPostFix(input);
}