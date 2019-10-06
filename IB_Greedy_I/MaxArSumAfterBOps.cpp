#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void print(std::vector<int> vi){
    std::cout<<"Vector:: ";
    for(auto i: vi){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

int maxArrSum(vector<int>& vi, int k){
    sort(begin(vi), end(vi));
    int index = 0;
    print(vi);
    while(index < vi.size() && k){
        if(vi[index] < 0){
            vi[index] = - vi[index];
            index++;
            k--;
        }
        else if(vi[index] == 0){
            k = 0;
            break;
        }
        else if(vi[index] > 0){
            int indexN = index == 0 ? index : index-1;
            if(vi[indexN] <= vi[index])
                vi[indexN] = -vi[indexN];
            else 
                vi[index] = -vi[index];
            k--;
        }
    }
    while(k){
        vi[index-1] = -vi[index-1];
        k--;
    }
    print(vi);
    int maxSum = 0;
    for(auto i: vi) maxSum += i;
    return maxSum;
}

int main(){
    vector<int> vi {57, 3, -14, -87, 42, 38, 31, -7, -28, -61};
    cout<<maxArrSum(vi, 10);

}