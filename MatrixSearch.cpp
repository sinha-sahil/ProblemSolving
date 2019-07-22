//
// Created by Sahil_Sinha on 2019-07-09.
//

#include<iostream>
#include<vector>
using namespace std;

int findElement(vector<vector<int>> matrix, int key){
    if(matrix.size() == 0) return -1;

    int col = matrix[0].size();
    int row = matrix.size();

    int sc = col -1;
    int sr = 0;

    int i=-1 , j= -1;

    while(sc >= 0 and sr<row){
        int current = matrix[sr][sc];
        if( current == key){
            i = sr;
            j = sc;
            break;
        }
        else if(current > key){
            sc--;
        }
        else if(current < key){
            sr++;
        }
    }

    if(i== -1) return -1;
    i++; j++;
    return (i*1009 + j);

}

int main(){
    int m , n;
    cin>>m>>n;
    vector<int> temp(n);
    vector<vector<int>> matrix(m, temp);
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) cin>>matrix[i][j];
    int key;
    cin>>key;
    cout<<findElement(matrix, key);
}