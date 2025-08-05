//Partition Equal subset sum

/*
    Problem Statment:
    find the partition of the array into two subsets such that the sum of both subsets is equal.

*/
/*
    Approach:
    Here wee need to find s1== s2 == s/2, where s is the sum of the array.

    so we can reduce this problem to subset sum equal to k problem.
    where k = s/2.

    Now we can use the subset sum problem approach to find if there exists a subset with sum k.
    Recursive, Memoization and Tabulation approaches can be used to solve this problem.

    it requires 2 min functions:
        check if the sum of the array is even.
        find the subset sum equal to k.

    check if the sum of the array is even:
        int sum = 0;
        for(int num : arr){
            sum += num;
        }
        return sum % 2 == 0;

    find the subset sum equal to k:
        we can use the same approach as in the Subset Sum Equal to K problem.
        bool canPartition(int ind, int target, vector<int> &arr) {
            if (target == 0) return true;
            if (ind == 0) return arr[ind] == target;

            bool notTake = canPartition(ind - 1, target, arr);
            bool take = false;
            if (target >= arr[ind]) {
                take = canPartition(ind - 1, target - arr[ind], arr);
            }
            return take || notTake;
        }


    memoization approach:
    bool canPartition(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
        if (target == 0) return true;
        if (ind == 0) return arr[ind] == target;

        if (dp[ind][target] != -1) return dp[ind][target];

        bool notTake = canPartition(ind - 1, target, arr, dp);
        bool take = false;
        if (target >= arr[ind]) {
            take = canPartition(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = take || notTake;
    }

    tabulation approach:
    bool canPartition(int n, int target, vector<int> &arr) {
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true; // sum 0 can always be formed with an empty subset
        }
        if (arr[0] <= target) {
            dp[0][arr[0]] = true; // only one element to consider
        }

        for (int ind = 1; ind < n; ind++) {
            for (int sum = 1; sum <= target; sum++) {
                bool notTake = dp[ind - 1][sum]; // not taking the current element
                bool take = false;
                if (sum >= arr[ind]) {
                    take = dp[ind - 1][sum - arr[ind]]; // taking the current element
                }
                dp[ind][sum] = take || notTake;
            }
        }
        return dp[n - 1][target];
    }

*/

#include <iostream>
#include <vector>
using namespace std;

bool subsetsum_rec(int ind, int k, vector<int> &arr){
    //base case:
    if(k==0) return true;
    if(ind ==0 ) return arr[ind]==k;

    // recursive case:
    bool nottake =  subsetsum_rec(ind-1,k,arr);
    bool take=false;
    if(k>=arr[ind]){
         take= subsetsum_rec(ind-1,k-arr[ind],arr);
    }
    return take || nottake;
}

bool subsetsum_memo(int ind, int k, vector<int> &arr, vector<vector<int>> &dp){
    //base case:
    if(k==0) return true;
    if(ind ==0 ) return arr[ind]==k;

    // check if already computed
    if(dp[ind][k]!= -1) return dp[ind][k];
    // recursive case:
    bool nottake =  subsetsum_memo(ind-1,k,arr, dp);
    bool take=false;
    if(k>=arr[ind]){
         take= subsetsum_memo(ind-1,k-arr[ind],arr, dp);
    }
    return dp[ind][k]= take || nottake;
}

bool subsetSum_tabulation(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // base case:
    for (int i = 0; i < n; i++) {
        dp[i][0] = true; // sum 0 can always be formed with an empty subset
    }
    if (arr[0] <= k) {
        dp[0][arr[0]] = true; // only one element to consider
    }

    // fill the dp table
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
    return dp[n - 1][k];
}

bool canPartition(vector<int>&arr){
    int sum=0;
    for(int i:arr){
        sum+=i;
        
    }
    if(sum%2!=0) return false; // if sum is odd, we cannot partition it into two equal subsets
    int k = sum / 2;
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    bool i = subsetsum_rec(n - 1, k, arr);
    cout << "Using Recursion: " << i << endl;

    // Call the memoization function
    vector<vector<int>> memo(n, vector<int>(k + 1, -1));
    bool j = subsetsum_memo(n - 1, k, arr, memo);
    cout << "Using Memoization: " << j << endl; 

    // Call the tabulation function
    bool y = subsetSum_tabulation(n, k, arr);
    cout << "Using Tabulation: " << y << endl;
}
int main() {
    vector<int> arr = {1, 5, 11, 5};
    
    if (canPartition(arr)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }
    
    return 0;
}   



