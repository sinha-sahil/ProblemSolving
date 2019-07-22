//
// Created by Sahil_Sinha on 2019-07-13.
//

#include <iostream>
using namespace std;

int factorial(int n){
    int answer = 1;
    for(int i=1;i<=n;i++) answer *=i;
    return answer;
}

int main(){
    int n;
    cin>>n;
    cout<<factorial(n);
}
