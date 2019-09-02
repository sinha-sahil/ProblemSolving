#include<iostream>
#include<vector>
using namespace std;

vector<int> sumList;
int ar[6][6];

int findMax(){
    int max= sumList[0];
    for(int i=0; i<16; i++)
        if(sumList[i] >= max)
            max= sumList[i];
    return max;
}

int calculateSum(int row, int col){
    int hourGlassSum=0;
    for(int r= row; r< row+3; r++){
        for(int c= col; c< col+3; c++){
            if(r== row+1 && c== col || r==row+1 && c== col+2){
                continue;
            } else{
                hourGlassSum+= ar[r][c];
            }
        }
    }
    return hourGlassSum;
}

int main(){
    for(int i=0; i<6; i++)
        for(int j=0; j<6; j++)
            cin>>ar[i][j];
    
    for(int k=0; k<4; k++){
        for(int r=0; r<4; r++){
            int newResult= calculateSum(k, r);
            sumList.push_back(newResult);
        }
    }
    int result= findMax();
    return 0;
}
