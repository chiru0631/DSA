//Minimum Platforms

/*
    Problem Statement:
    You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a railway station on the same day. 
    Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.

    At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. 
    Therefore, when two trains arrive at the same time, or when one arrives before another departs, 
    additional platforms are required to accommodate both
*/

/*
    Approach:
    1. create vector of pairs to store arrival and departure times
       - vector<pair<int, int>> trains;// strores arrival and departure times
    2. sort them based on departure times
       - sort(trains.begin(), trains.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
           return a.second < b.second;
       });
    3. Initialize a variable to keep track of the number of platforms needed.
       - int platforms = 0;
    4. Initialize a variable to keep track of the maximum number of platforms needed at any time.
       - int maxPlatforms = 0;
    5. Iterate through the sorted trains:
       while (i < trains.size()) {
           - If the current train's arrival time is less than or equal to the last train's departure time, 
             it means we need an additional platform.
             - platforms++;
             if(arr[i] <= dep[j]) {
                 platforms++;
                 i++;// Move to the next train
             }
            
           - If the current train's arrival time is greater than the last train's departure time, 
             it means one platform can be freed up.
             - platforms--;
           - Update maxPlatforms with the maximum value of platforms seen so far.
       }

    
    Dry Run:
    arr: [10, 12, 20]
    dep: [20, 25, 30]
    1. Create vector of pairs: trains = [(10, 20), (12, 25), (20, 30)]
    2. Sort trains based on departure times: trains = [(10, 20), (12, 25), (20, 30)]
    3. Initialize platforms = 0, maxPlatforms = 0
    4. Start iterating through the trains:
       - i = 0: trains[0] = (10, 20)
         - platforms = 1 (train arrives at 10)
         - maxPlatforms = 1
       - i = 1: trains[1] = (12, 25)
         - platforms = 2 (train arrives at 12)
         - maxPlatforms = 2
       - i = 2: trains[2] = (20, 30)
         - platforms = 1 (train departs at 20)
         - maxPlatforms remains 2

   */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minplatforms(vector<int>& arr, vector<int>& dep){
    vector<pair<int,int>> trains;
    for(int i=0;i<arr.size();i++){
        trains.push_back({arr[i],dep[i]});

    }
    sort(trains.begin(),trains.end(),[](const pair<int,int>& a, const pair<int,int>& b){
        return a.second < b.second; // sort by departure time
    });
    int paltforms=0; // number of platforms needed
    int maxPlatforms=0; // maximum number of platforms needed at any time
    int i=0, j=0; // i for arrival, j for departure

    while(i< trains.size()){
        if(trains[i].first <= trains[j].second){
            paltforms++; // if the current train's arrival time is less than or equal to the last train's departure time, we need an additional platform
            maxPlatforms = max(maxPlatforms, paltforms); // update the maximum number of platforms needed
            i++; // move to the next train
        } else {
            paltforms--; // if the current train's arrival time is greater than the last train's departure time, one platform can be freed up
            j++; // move to the next departure
        }
    }
    return maxPlatforms;
}

int main() {
    vector<int> arr = {10, 12, 20};
    vector<int> dep = {20, 25, 30};
    cout << "Minimum number of platforms required: " << minplatforms(arr, dep) << endl;
    return 0;
}