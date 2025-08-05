// Partation a set into 2 subsets such that the difference of subset sum is minimum

/*
    Problem Statment:
    Given an array, partition it into two subsets such that the difference of subset sum is minimum

    example:
    Input: arr = {1, 6, 11, 5}
    Output: 1
    Explanation: The two subsets are {1, 5, 6} and {11}, with sums 12 and 11 respectively. The difference is 1.
*/

/*
    Approach:
    1. Calculate the total sum of the array.
    2. The problem can be reduced to finding a subset with sum equal to (total_sum / 2).
    3. Use the subset sum problem approach to find the maximum subset sum that is less than or equal to (total_sum / 2).
    4. The minimum difference will be (total_sum - 2 * max_subset_sum).

    min subset sum difference:
    int minsubsetsumdiff(vector<int> &arr, int n){
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    int k = total_sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true; // sum 0 can always be formed with an empty subset
    }
    if (arr[0] <= k) {
        dp[0][arr[0]] = true; // only one element to consider
    }
    for (int ind = 1; ind < n; ind++) {
        for (int sum = 1; sum <= k; sum++) {
            bool notTake = dp[ind - 1][sum]; // not taking the current element
            bool take = false;
            if (sum >= arr[ind]) {
                take = dp[ind - 1][sum - arr[ind]]; // taking the current element
            }
            dp[ind][sum] = take || notTake;
        }
    }

    int mini= 1e9;
    for (int i = 0; i <= k; i++) {
        if (dp[n - 1][i]) {
            mini = min(mini, total_sum - 2 * i);
        }
    }
    return mini;
}

*/

/*
    time complexity: O(n*k)
    space complexity: O(n*k)
    where n is the number of elements in the array and k is the target sum (total_sum / 2).
*/

#include <iostream>
#include <vector>
#include <numeric> // for accumulate
#include <algorithm> // for min
using namespace std;

int minsubdiff(vector<int> &arr){
    int total_sum = accumulate(arr.begin(),arr.end(),0);
    int k = total_sum / 2;
    int n = arr.size();

    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    // base case:
    for(int i=0;i<n;i++){
        dp[i][0]= true; // sum 0 can always be formed with an empty subset
    }
    if(arr[0] <= k){
        dp[0][arr[0]] = true; // only one element to consider
    }

    // fill the dp table
    for( int ind=1;ind<n;ind++){
        for(int sum=1;sum<=k;sum++){
            bool nottake = dp[ind-1][sum];
            bool take = false;
            if(sum >= arr[ind]){
                take = dp[ind-1][sum-arr[ind]];
            }  
            dp[ind][sum] = take || nottake;
        }
    }

    int mini = 1e9;
    for(int i=0;i<=k;i++){
        if(dp[n-1][i]){
            mini = min(mini, total_sum - 2*i);
        }
    }
    return mini;

}

int main() {
    vector<int> arr = {1, 6, 11, 5};
    cout << "Minimum subset sum difference: " << minsubdiff(arr) << endl;
    return 0;
}