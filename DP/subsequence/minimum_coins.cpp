//Minimum coins 

/*
    Problem Statement:
    Given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money,
    return the fewest number of coins that you need to make up that amount.
    If that amount of money cannot be made up by any combination of the coins, return -1.

    Example:
    Input: coins = [1, 2, 5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1
*/
/*

    Recurrence Approach:
    use take and not take approach:
    1. Base Case: If amount is 0, return 0 (no coins needed).
    if(ind == 0) {
        if(amount % coins[0] == 0) return amount / coins[0];
        return 1e9; // if we cannot form the amount with the first coin
    }
    2. If we take the current coin, reduce the amount by coins[ind] and move to the next index.
    3. If we do not take the current coin, just move to the next index without changing the amount.
    int notTake = coinChange(ind - 1, amount, coins);
    int take = INT_MAX;
    if (amount >= coins[ind]) {
        take = 1 + coinChange(ind, amount - coins[ind], coins);
    }
    return min(take, notTake);


    memoization Approach:
    1. Create a 2D array dp of size (n x amount + 1) initialized to -1.
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    2. base case: 
    if the index is 0, check if the amount can be formed with the first coin.
    if(ind==0){
        if(amount % coins[0] == 0) return amount / coins[0];
        return 1e9; // if we cannot form the amount with the first coin
    
    }
    3. Check if the current state is already computed (dp[ind][amount] != -1).
    if(dp[ind][amount] != -1) return dp[ind][amount];

    4. If not computed, calculate the result using the recursive approach and store it in dp[ind][amount].
    int notTake = coinChange(ind - 1, amount, coins, dp); 
    int take = 1e9;
    if (amount >= coins[ind]) {
        take = 1 + coinChange(ind, amount - coins[ind], coins, dp);
    }
    dp[ind][amount] = min(take, notTake);
    return dp[ind][amount];


    tabulation Approach:
    1. Create a 2D array dp of size (n x amount + 1) initialized to INT_MAX.
    vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));
    2. base case:
        // if amount is 0, then we need 0 coins to form the amount.
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        if (coins[0] <= amount) {
            dp[0][coins[0]] = 1; // only one coin to consider
        }

    // fill the dp table
    for (int ind = 1; ind < n; ind++) {
        for (int amt = 1; amt <= amount; amt++) {
            int notTake = dp[ind - 1][amt]; // not taking the current coin
            int take = INT_MAX;
            if (amt >= coins[ind]) {
                take = 1 + dp[ind][amt - coins[ind]]; // taking the current coin
            }
            dp[ind][amt] = min(take, notTake);
        }
    }
    return dp[n - 1][amount] == INT_MAX ? -1 : dp[n - 1][amount];
}
*/

#include <iostream>
#include <vector>
#include <algorithm> // for min
using namespace std;

int mincoins_rec(vector<int> &coins , int ind, int amount){
    // base case:
    if(ind==0){
        if(amount%coins[0]==0) return amount/coins[0];
        return 1e9; // if we cannot form the amount with the first coin
    }

    // recursive case:
    int notTaken=  mincoins_rec(coins, ind-1, amount);
    int taken= 1e9;
    if(amount>=coins[ind]){
        taken= 1+ mincoins_rec(coins, ind, amount-coins[ind]);
    }
    return min(taken, notTaken);
}

int mincoin_memo(vector<int> &coins, int ind, int amount, vector<vector<int>>&dp){
    //base case:
    if(ind==0){
        if(amount%coins[0]==0) return amount/coins[0];
        return 1e9; // if we cannot form the amount with the first coin
    }
    // check if already computed
    if(dp[ind][amount] != -1) return dp[ind][amount];

    // recursive case:
    int notTaken=  mincoin_memo(coins, ind-1, amount, dp);
    int taken= 1e9;
    if(amount>=coins[ind]){
        taken= 1+ mincoin_memo(coins, ind, amount-coins[ind], dp);
    }
    return dp[ind][amount] = min(taken, notTaken);
}

int mincoin_tabulation(vector<int> &coins, int n, int amount) {
    vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));

    // base case:
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0; // if amount is 0, then we need 0 coins to form the amount
    }
    if (coins[0] <= amount) {
        dp[0][coins[0]] = 1; // only one coin to consider
    }

    // fill the dp table
    for (int ind = 1; ind < n; ind++) {
        for (int amt = 1; amt <= amount; amt++) {
            int notTake = dp[ind - 1][amt]; // not taking the current coin
            int take = INT_MAX;
            if (amt >= coins[ind]) {
                take = 1 + dp[ind][amt - coins[ind]]; // taking the current coin
            }
            dp[ind][amt] = min(take, notTake);
        }
    }
    
    return dp[n - 1][amount] == INT_MAX ? -1 : dp[n - 1][amount];
}
int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int n = coins.size();

    // Using Recursion
    cout << "Minimum coins (Recursion): " << mincoins_rec(coins, n - 1, amount) << endl;

    // Using Memoization
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    cout << "Minimum coins (Memoization): " << mincoin_memo(coins, n - 1, amount, dp) << endl;

    // Using Tabulation
    cout << "Minimum coins (Tabulation): " << mincoin_tabulation(coins, n, amount) << endl;

    return 0;
}



