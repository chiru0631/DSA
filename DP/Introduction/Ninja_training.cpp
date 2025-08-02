//Ninja

/*
    Problem Statement:
    Ninja is planing this ‘N’ days-long training schedule. 
    Each day, he can perform any one of these three activities. 
    (Running, Fighting Practice or Learning New Moves). 
    Each activity has some merit points on each day. 
    As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. 
    Can you help Ninja find out the maximum merit points Ninja can earn?

    You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. 
    Your task is to calculate the maximum number of merit points that Ninja can earn.
*/

/*
    Approach:
    //0 -> task 0 (starting day)
    //1 -> running 
    //2 -> fighting practice
    //3 -> learning new moves

    base case:
    if(ind == 0){
     take a maxi variable initialized to 0.
     for(int i=0;i<3;i++){
        if(i != last) // If the current activity is not the last one performed
            maxi = max(maxi, points[0][i]); // Update max with the points of the current activity
    return maxi; // Return the maximum points for the first day
     }

    maxi = 0 once again initalize to 0.
    for(int i=0;i<3;i++){
        if(i != last) // If the current activity is not the last one performed
            points = points[day][i]+f(day-1,i);
            maxi = max(maxi,points); // Update max with the points of the current activity
    }
    return maxi; // Return the maximum points for the first day
}


    memoization approach:
    1. Create a 2D vector to store the maximum points for each day and last activity.
       vector<vector<int>> dp(n, vector<int>(4, -1));
    2. base case:
       if(ind == 0) {
           int maxi = 0;
           for(int i = 0; i < 3; i++) {
               if(i != last) // If the current activity is not the last one performed
                   maxi = max(maxi, points[0][i]); // Update max with the points of the current activity
           }
           return maxi; // Return the maximum points for the first day
       }
    3. check if the value is already calculated:
       if(dp[ind][last] != -1) return dp[ind][last];
    4. Initialize a variable to store the maximum points for the current day.
       int maxi = 0;
    5. Iterate through the activities and calculate the maximum points for the current day:
       for(int i = 0; i < 3; i++) {
           if(i != last) { // If the current activity is not the last one performed
               int points = points[ind][i] + f(ind - 1, i, points, dp); // Calculate points for the current activity
               maxi = max(maxi, points); // Update max with the points of the current activity
           }
       }
       dp[ind][last] = maxi; // Store the calculated value in the dp array
       return maxi;
   }
   6. Call the recursive function and return the result:
   return f(n - 1, -1, points, dp);
}

    Tabulation approach:
    1. Create a 2D vector to store the maximum points for each day and last activity.
       vector<vector<int>> dp(n, vector<int>(4, 0));
    2. Base case:
       for(int i = 0; i < 3; i++) {
           if(i != last) // If the current activity is not the last one performed
               dp[0][i] = points[0][i]; // Initialize the first day with the points of the current activity
       }
    3. Iterate through the days and activities:
       for(int day = 1; day < n; day++) {
           for(int last = 0; last < 4; last++) {
               int maxi = 0;
               for(int i = 0; i < 3; i++) {
                   if(i != last) { // If the current activity is not the last one performed
                       int points = points[day][i] + dp[day - 1][i]; // Calculate points for the current activity
                       maxi = max(maxi, points); // Update max with the points of the current activity
                   }
               }
               dp[day][last] = maxi; // Store the calculated value in the dp array
           }
       }
    4. Return the maximum points from the last day:
       return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
*/  

/*
    Time Complexity: O(n * 3) - Linear time complexity due to the nested loops for days and activities.
    Space Complexity: O(n * 4) - Due to the 2D vector used for memoization or tabulation.

    memoization approach:
    time complexity: O(n * 3) - Linear time complexity due to the recursive calls and memoization.
    space complexity: O(n * 4) - Due to the 2D vector used for memoization.

    tabulation approach:
    time complexity: O(n * 3) - Linear time complexity due to the nested loops
    space complexity: O(n * 4) - Due to the 2D vector used for tabulation.
*/

#include <iostream>
#include <vector>
using namespace std;

int ninjatraining_recursion(int ind, int last, vector<vector<int>>& points){
    //base case
    if(ind == 0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!= last) { // If the current activity is not the last one performed
                maxi = max(maxi, points[0][i]); // Update max with the points of the current activity
            }
        }
        return maxi; // Return the maximum points for the first day
    }

    int maxi=0; // Initialize a variable to store the maximum points for the current day.
    for(int i=0;i<3;i++){
        if(i!= last){
            int points_today = points[ind][i] + ninjatraining_recursion(ind - 1, i, points); // Calculate points for the current activity
            maxi = max(maxi, points_today); // Update max with the points of the current activity
        }
    }
    return maxi;
}

int ninjatraining_memoization(int ind, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
    //base case
    if(ind == 0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!= last) { // If the current activity is not the last one performed
                maxi = max(maxi, points[0][i]); // Update max with the points of the current activity
            }
        }
        return maxi; // Return the maximum points for the first day
    }

    if(dp[ind][last] != -1) return dp[ind][last]; // If the value is already calculated, return it.

    int maxi=0; // Initialize a variable to store the maximum points for the current day.
    for(int i=0;i<3;i++){
        if(i!= last){
            int points_today = points[ind][i] + ninjatraining_memoization(ind - 1, i, points, dp); // Calculate points for the current activity
            maxi = max(maxi, points_today); // Update max with the points of the current activity
        }
    }
    dp[ind][last] = maxi; // Store the calculated value in the dp array
    return maxi;
}   

int ninjatraining_tabulation(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(4, 0)); // Create a 2D vector to store the maximum points for each day and last activity.

    // Base case
    for(int i = 0; i < 3; i++) {
        if(i != 3) // If the current activity is not the last one performed
            dp[0][i] = points[0][i]; // Initialize the first day with the points of the current activity
    }

    // Iterate through the days and activities
    for(int day = 1; day < n; day++) {
        for(int last = 0; last < 4; last++) {
            int maxi = 0;
            for(int i = 0; i < 3; i++) {
                if(i != last) { // If the current activity is not the last one performed
                    int points_today = points[day][i] + dp[day - 1][i]; // Calculate points for the current activity
                    maxi = max(maxi, points_today); // Update max with the points of the current activity
                }
            }
            dp[day][last] = maxi; // Store the calculated value in the dp array
        }
    }

    // Return the maximum points from the last day
    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}

int main() {
    int n= 5;
    vector<vector<int>> points(n, vector<int>(3)); // 2D vector to store points for each day and activity

    // Input points for each day and activity
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            points[i][j] = rand() % 10 + 1; // Random points between 1 and 10 for demonstration
            cout << points[i][j] << " "; // Print the points for each day and activity
        }
        cout << endl; // New line after each day's points   
    }

    // Memoization approach
    vector<vector<int>> dp(n, vector<int>(4, -1)); // Initialize dp array with -1
    cout << ninjatraining_memoization(n - 1, 3, points, dp) << endl;//out

    // Tabulation approach
    cout << ninjatraining_tabulation(n, points) << endl;

    return 0;
}