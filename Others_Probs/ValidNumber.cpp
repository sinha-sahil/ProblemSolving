#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


bool isValidDigit(int ascii){
    if((ascii>47 and ascii<58) or (ascii == 101) ) return true;
    return false;
}

int isNumber(const string input) {
    bool e= false;
    int eIndex=-1;
    int minEindex = 0;
    bool dot= false;
    bool digit= false;
    bool space = false;
    int spaceIndex = -1;
    int firstDigit = -1;
    int lastDigit = -1;
    
    for(int i=0; i<input.size(); i++){
       // cout<<"-"<<input[i];
        int ascii = static_cast<int>(input[i]);
        if(input[i]=='-'){
            cout<<"from minus";
            cout<<endl;
            if(i==0) continue;
            else if(minEindex ==0) minEindex++;
            else return false;
        }
        else if(input[i]=='.'){
            cout<<"from dot";
            cout<<endl;
            if(e) return false;
            if(not dot) dot= true;
            else if(dot) return false;
            if(i== input.size()-1 ) return false;
            else continue;
        }
        else if(input[i]==' '){
            cout<<"from space";
            cout<<endl;
            if (space) continue;
            else if(digit) {space = true; spaceIndex =i;}
            else continue;
        }
        else if(isValidDigit(ascii)){
            cout<<"from digit";
            cout<<endl;
            digit = true;
            if(firstDigit ==-1) firstDigit= i;
            lastDigit = i;
            if(input[i]== 'e'){
                if(i>0 and input[i-1]=='.') { cout<<"Ecase"; return false;}
                if(not e) e= true;
                else if(e) return false;
                eIndex= i;
            }
        }
        else if(!isValidDigit(ascii)) {cout<<"NoValidDigit"; return false;}
    }
    cout<<"Came here";
    if(not digit) return false;
    if(space and spaceIndex<lastDigit ) {cout<<"From here"; return false;}
    if(eIndex ==0 or eIndex==input.size()-1) {cout<<"From here"; return false;}
    return true;
}

int main(){
    string input = "32467826570812365702673647926314796457921365792637946579269236594265794625762375621765476592146926410592659021465904652.687236478235187653874637824647856428756387264578245676579032657906097542609  ";
    int op= isNumber(input);
    cout<<"\nresult: "<<op;

}
