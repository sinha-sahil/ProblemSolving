#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin>>n;
    int sum=0;
    for(int i=1; i<=n; i++)
        sum+=i;
    int modValue= pow(10, 9) +7;
    int result= sum% modValue;
    cout<<result;
    return 0;
}
