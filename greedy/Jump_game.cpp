//55. Jump Game

/*
    You are given an integer array nums. You are initially positioned at the array's first index, 
    and each element in the array represents your maximum jump length at that position.

    Return true if you can reach the last index, or false otherwise.
*/

/*
    To solve this problem, we can use a greedy approach.

    Approach:
    1. Initialize a variable `maxReach` to keep track of the farthest index we can reach.
       - int maxReach = 0; 
    2. Iterate through the array using a for loop.
       - for (int i = 0; i < nums.size(); i++) {
           - if (i > maxReach) {
               - return false;// If the current index is beyond the farthest reachable index, return false
           - }
           - maxReach = max(maxReach, i + nums[i]);
       - }
       return true;
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool canjump(vector<int>& nums){
    int maxreach=0;// farthest index we can reach
    for(int i=0;i<nums.size();i++){
        if(i>maxreach){
            return false; // If the current index is beyond the farthest reachable index, return false
        }
        maxreach=max(maxreach,i+nums[i]); // update the farthest reachable index
        if(nums.size()-1<=maxreach){
            return true; // If we can reach the last index, return true
        }
    }
    return false; // If we finish the loop without reaching the last index, return false
}

int main(){
    vector<int> nums = {2, 3, 1, 1, 4};
    if(canjump(nums)){
        cout << "You can reach the last index." << endl;
    } else {
        cout << "You cannot reach the last index." << endl;
    }
    return 0;
}

