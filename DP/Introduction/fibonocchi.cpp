// Fibonacci series using dp

/*
    Problem Statement:
    Given a number n, find the nth Fibonacci number.
    The Fibonacci sequence is defined as follows:
    F(0) = 0
    F(1) = 1
    F(n) = F(n-1) + F(n-2) for n > 1
*/

/*
    Approach:
    

    1// recursive approach
       1. Base case: If n is 0, return 0; if n is 1, return 1.
       2. Recursive case: Return the sum of the Fibonacci numbers for n-1 and n-2.
       fib(n){
              if(n == 0) return 0;
              if(n == 1) return 1;
              return fib(n-1) + fib(n-2);
       }


       time complexity: O(2^n) - exponential time complexity due to the repeated calculations of the same Fibonacci numbers.
       space complexity: O(n) - due to the recursive call stack.

    2// memoization approach
       memoization is a technique where we store the results of expensive function calls and reuse them when the same inputs occur again.
       this is used in overlapping subproblems.
       this is a top-down approach.

       in this approach, we break the bigger problem int smaller subproblems and store the results of the smaller subproblems in a vector.
       when we need to calculate the Fibonacci number for n, we first check if it is already calculated and stored in the vector.

    1. Create a vector to store the Fibonacci numbers.
    2. check for the base cases:
       if n is 0, return 0; if n is 1, return 1.
    3. If the Fibonacci number for n is already calculated, return it.
    4. Otherwise, calculate the Fibonacci number for n using the recursive formula and store it in the vector.
    5. Return the Fibonacci number for n.

    time complexity: O(n) - linear time complexity due to the memoization.
    space complexity: O(n) - due to the vector used for memoization and the recursive

    3// tabulation approach
        tabulation is a technique where we solve the problem by breaking it down into smaller subproblems and storing the results in a table.
        its a bottom-up approach.

        in this approach, we start from the base cases(from smaller subproblems) and build up the solution to the bigger problem.

    1. Create a vector to store the Fibonacci numbers.
    2. Initialize the first two Fibonacci numbers in the vector.
     dp[0] = 0;
     dp[1] = 1;
    3. Iterate from 2 to n, calculating the Fibonacci number for each index using the previous two numbers.
       dp[i] = dp[i-1] + dp[i-2];
    4. Return the Fibonacci number for n.

    time complexity: O(n) - linear time complexity due to the tabulation.
    space complexity: O(n) - due to the vector used for tabulation.

*/


#include<iostream>
#include <vector>
using namespace std;

// using recursion
int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1)+fib(n-2);

}

// using memoization
int fibmemo(int n, vector<int>& dp){
    if(n==0) return 0;
    if(n==1) return 1;

    if(dp[n] !=-1) return dp[n];
    dp[n]= fibmemo(n-1,dp)+fibmemo(n-2,dp);
    return dp[n];
}

// using tabulation

int fibtab(int n){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main() {
    int n= 10; // Example input for the Fibonacci number to calculate
    

    // Using recursion
    cout << "Fibonacci number using recursion: " << fib(n) << endl;

    // Using memoization
    vector<int> dp(n + 1, -1);
    cout << "Fibonacci number using memoization: " << fibmemo(n, dp) << endl;

    // Using tabulation
    cout << "Fibonacci number using tabulation: " << fibtab(n) << endl;

    return 0;
}

