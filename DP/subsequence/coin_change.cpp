// ways to make coin change problem

/*
    Problem Statement:
    Given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money,
    return the number of combinations that make up that amount. If that amount cannot be made up by any combination of the coins, return 0.

    Example:
    Input: coins = [1, 2, 5], amount = 5
    Output: 4
    Explanation: There are four ways to make up the amount:
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1
*/

/*
    approach:
    we will be using pick and not pick approach

    Recurrence Approach:
    1. Base Case: If amount is 0, return 1 (one way to make up the amount).
    if (ind==0){
        if (amount % coins[0] == 0) return 1; // if we can form the amount with the first coin
        return 0; // if we cannot form the amount with the first coin
    }
    2. If we take the current coin, reduce the amount by coins[ind] and move to the next index.
    3. If we do not take the current coin, just move to the next index
    int notTake = coinChange(ind - 1, amount, coins);
    int take = 0;
    if (amount >= coins[ind]) {
        take = coinChange(ind, amount - coins[ind], coins);
    }
    return take + notTake;

    recusive approach:
    if(amount == 0) return 1; // base case: if amount is 0, we can form it with an empty subset
    if(ind == 0) {
        if(amount % coins[0] == 0) return 1; // if we can form the amount with the first coin
        return 0; // if we cannot form the amount with the first coin
    }


    Memoization Approach:
    1. Create a 2D array dp of size (n x amount + 1) initialized to -1.
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    2. base case:
    if (ind == 0) {
        if (amount % coins[0] == 0) return 1; // if we can form the amount with the first coin
        return 0; // if we cannot form the amount with the first coin
    }

    3. Check if the current state is already computed (dp[ind][amount] != -1).
    if (dp[ind][amount] != -1) return dp[ind][amount];

    4. If not computed, calculate the result using the recursive approach and store it in dp[ind][amount].
    int notTake = coinChange(ind - 1, amount, coins, dp);
    int take = 0;
    if (amount >= coins[ind]) {
        take = coinChange(ind, amount - coins[ind], coins, dp);
    }
    return dp[ind][amount] = take + notTake;


    tabulation Approach:
    1. Create a 2D array dp of size (n x amount + 1) initialized to 0.
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    2. base case:
        // if amount is 0, then we need 1 way to form the amount.
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        if (coins[0] <= amount) {
            dp[0][coins[0]] = 1; // only one coin to consider
        }
    }

    3. Fill the dp array using the recurrence relation.
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= amount; j++) {
            int notTake = dp[i-1][j]; // not taking the current coin
            int take = 0;
            if (j >= coins[i]) {
                take = dp[i][j-coins[i]]; // taking the current coin
            }
            dp[i][j] = take + notTake;
        }
    }
    return dp[n-1][amount];
*/


#include <iostream>
#include <vector>
using namespace std;

int coin_change_rec(vector<int> &coins, int ind, int amount){
    if(ind==0){
        if(amount % coins[0]==0) return 1; // if we can form the amount with the first coin
        return 0; // if we cannot form the amount with the first coin
    }
    // check if already computed
    int notTaken = coin_change_rec(coins, ind-1, amount); // not taking the current coin
    int taken =0;
    if(amount >= coins[ind]){
        taken = coin_change_rec(coins, ind, amount-coins[ind]); // taking the current coin
    }
    return taken + notTaken;
}

int coin_change_memo(vector<int> &coins, int ind, int amount, vector<vector<int>>& dp){
    if(ind==0){
        if(amount % coins[0]==0) return 1; // if we can form the amount with the first coin
        return 0; // if we cannot form the amount with the first coin
    }
    //check if already computed
    if(dp[ind][amount] != -1) return dp[ind][amount];

    //recursive case:
    int nottaken = coin_change_memo(coins, ind-1, amount, dp); // not taking the current coin
    int taken = 0;
    if(amount >= coins[ind]){
        taken = coin_change_memo(coins, ind, amount-coins[ind], dp); // taking the current coin
    }
    return dp[ind][amount] = taken + nottaken;
}

int coin_change_tabulation(vector<int> &coins, int n, int amount) {
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // base case: amount 0 can be formed in 1 way (take nothing)
    for (int i = 0; i < n; i++) dp[i][0] = 1;

    // initialize the first row: use only coins[0]
    for (int j = 0; j <= amount; j++) {
        if (j % coins[0] == 0)
            dp[0][j] = 1;
    }

    // fill dp table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= amount; j++) {
            int notTaken = dp[i-1][j];
            int taken = 0;
            if (j >= coins[i]) taken = dp[i][j - coins[i]];
            dp[i][j] = taken + notTaken;
        }
    }

    return dp[n-1][amount];
}


int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int n = coins.size();

    // Recursive approach
    cout << "Recursive: " << coin_change_rec(coins, n - 1, amount) << endl;

    // Memoization approach
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    cout << "Memoization: " << coin_change_memo(coins, n - 1, amount, dp) << endl;

    // Tabulation approach
    cout << "Tabulation: " << coin_change_tabulation(coins, n, amount) << endl;

    return 0;
}