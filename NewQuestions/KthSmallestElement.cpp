#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int findKtheSmallest(const vector<int>& vi, int k ){
    int minElement = *min_element(begin(vi), end(vi));
    int maxElement = *max_element(begin(vi), end(vi));

    while(minElement < maxElement){
        int lessCount = 0;
        int equalCount = 0;
        int midElement = minElement + (maxElement-minElement)/2;
        for(int i=0; i<vi.size(); i++){
            if(vi[i] < midElement) lessCount++;
            else if(vi[i] == midElement) equalCount++;
        }
        if(lessCount < k && (lessCount+equalCount <= k)) return midElement;
        else if (lessCount >=k) maxElement = midElement - 1;
        else minElement = midElement + 1;
    }

    return 0;
}