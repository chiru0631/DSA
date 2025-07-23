//45. Jump Game II

/*
    You are given a 0-indexed array of integers nums of length n. 
    You are initially positioned at nums[0].

    Each element nums[i] represents the maximum length of a forward jump from index i. 
    In other words, if you are at nums[i], you can jump to any nums[i + j] where:

    0 <= j <= nums[i] and
    i + j < n

    Return the minimum number of jumps to reach nums[n - 1]. 
    The test cases are generated such that you can reach nums[n - 1].    

*/

/*
    Approach:
    1. Initialize a variable `jumps` to keep track of the number of jumps made.
       - int jumps = 0;
    2. Initialize a variable `currentEnd` to keep track of the farthest index that can be reached with the current number of jumps.
       - int currentEnd = 0;
    3. Initialize a variable `farthest` to keep track of the farthest index that can be reached with the next jump.
       - int farthest = 0;
    4. Iterate through the array using a for loop.
       - for (int i = 0; i < n - 1; i++) {
           - farthest = max(farthest, i + nums[i]);
           - if (i == currentEnd) {
               - jumps++;
               - currentEnd = farthest;
           - }
       - }
       return jumps;


    Dry Run:
    array: [2, 3, 1, 1, 4]
    n = 5
    1. Initialize jumps = 0, currentEnd = 0, farthest = 0
    2. Start iterating through the array:   
    - i = 0: farthest = max(0, 0 + 2) = 2
    - i = 1: farthest = max(2, 1 + 3) = 4
    - i = 2: farthest = max(4, 2 + 1) = 4   
    - i = 3: farthest = max(4, 3 + 1) = 4
    - i = 4: farthest = max(4, 4 + 4) = 8
    3. When i = 1, currentEnd = 0, we increment jumps to 1 and update currentEnd to farthest (2).
    4. When i = 2, currentEnd = 2, we increment jumps to 2 and update currentEnd to farthest (4).
    5. When i = 3, currentEnd = 4, we increment jumps to 3 and update currentEnd to farthest (8).
    6. The loop ends, and we return jumps = 3.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums){
    int jumps=0; // number of jumps made
    int currentEnd=0; // farthest index that can be reached with the current number of jumps
    int farthest=0; // farthest index that can be reached with the next jump
    for(int i=0;i<nums.size()-1;i++){
        farthest=max(farthest,i+nums[i]); // update the farthest index that can be reached
        if(i==currentEnd){ // if we have reached the end of the current jump
            jumps++; // increment the number of jumps
            currentEnd=farthest; // update the end of the current jump to the farthest index
        }
    }
    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    int result = jump(nums);
    cout << "Minimum number of jumps to reach the last index: " << result << endl;
    return 0;
}