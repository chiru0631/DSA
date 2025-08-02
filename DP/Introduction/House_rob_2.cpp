//213. House Robber II

/*
    Problem Statement:
        You are a professional robber planning to rob houses along a street. 
        Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
        That means the first house is the neighbor of the last one. 
        Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police 
        if two adjacent houses were broken into on the same night.

        Given an integer array nums representing the amount of money of each house,
        return the maximum amount of money you can rob tonight without alerting the police.
*/

/*
    Input: nums = [2,3,2]
    Output: 3
    Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

*/

/*
    Appeoach: using recursion with memoization

    1. take the size of the array.
    2. if the size is 1, return the first element.
    3. create 2 vector to store the results of two cases:
       - excluding the first house
       - excluding the last house
    4. iterate through the array and calculate the maximum amount of money that can be robbed
       if(i!= 0) then we can rob the current house and add it to the result of the previous house
          array1.push_back(nums[i])
        if(i!= n-1) then we can rob the current house and add it to the result of the previous house
          array2.push_back(nums[i])
    5. return the maximum of the two results.
          return max(findmax(array1), findmax(array2));


    Findmax function:
    // to find the max sum of non-adjacent houses
    1. take the size of the array.
    2. if the size is 0, return 0.
    3. if the size is 1, return the first element.
    4. create a dp array of size n+1 initialized to -1.
    5. dp[0] = 0.
    6. take a neg variable initialized to 0.
    7. iterate through the array and calculate the maximum amount of money that can be robbed
       if(i!= 0) then we can rob the current house and add it to the result of the previous house
          dp[i] = max(dp[i-1], dp[i-2] + nums[i])
    8. return the maximum amount of money that can be robbed
       return dp[n-1];

*/

#include <iostream>
#include <vector>
using namespace std;

int findmax(vector<int>& nums){
    int n=nums.size();
    if(n==0) return 0; // If the size is 0, return 0.
    vector<int> dp(n+1);
    dp[0] = 0; // Base case: If there are no houses, the maximum amount is 0.
    dp[1] = nums[0]; // If there is one house, the maximum amount is the money in that house.
    for(int i=1;i<n;i++){
        int take = nums[i]; // Take the current house's money.
        if(i > 1) take += dp[i-2]; // If not the first house, add the maximum from two houses back.
        dp[i] = max(dp[i-1], take); // Max of not taking the current house and taking it.
    }
    return dp[n-1]; // Return the maximum amount of money that can be robbed.

}

int robhouse2(vector<int>& nums){
    int n= nums.size();
    
    if(n==1) return nums[0]; // If the size is 1, return the first element.
    
    vector<int> array1, array2; // Vectors to store the results of two cases.
    for(int i=0;i<n;i++){
        if(i!=0)array1.push_back(nums[i]); // Exclude the first house
        if(i!=n-1)array2.push_back(nums[i]); // Exclude the last house
    }
    return max(findmax(array1), findmax(array2)); // Return the maximum of the two results.
}

int main() {
    vector<int> nums = {2, 3, 2};
    cout << "Maximum amount of money that can be robbed: " << robhouse2(nums) << endl;//output: 3
    
    // Testing with another example
    vector<int> nums2 = {1, 2, 3, 1};
    cout << "Maximum amount of money that can be robbed: " << robhouse2(nums2) << endl;//output: 4

    return 0;
}   