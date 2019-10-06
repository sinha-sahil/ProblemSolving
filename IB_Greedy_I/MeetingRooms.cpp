#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int meetingRooms(vector<vector<int>> vi){
    vector<int> sTime;
    vector<int> eTime;
    for(auto i : vi){
        sTime.push_back(i[0]);
        eTime.push_back(i[1]);
    }
    sort(begin(sTime), end(sTime));
    sort(begin(eTime), end(eTime));
    int index1 = 0, index2 = 0;
    int currentCount = 0;
    int maxRooms = 1;
    while(index1 < sTime.size() && index2 < eTime.size()){
        if(sTime[index1] < eTime[index2]){
            currentCount++;
            index1++;
        }
        else{
            maxRooms = max(maxRooms, currentCount);
            currentCount--;
            index2++;
        }
    }
    maxRooms = max(maxRooms, currentCount);
    return maxRooms;
}