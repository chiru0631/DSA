//322. Coin Change

/*

    You are given an integer array coins representing coins of different denominations and an integer amount 
    representing a total amount of money.

    Return the fewest number of coins that you need to make up that amount. 
    If that amount of money cannot be made up by any combination of the coins, return -1.

    You may assume that you have an infinite number of each kind of coin.

*/

/*
    Pattern : Greedy
    Time Complexity : O(n * amount)
    Space Complexity : O(amount)

    Approach :
    1. create a vector of ans to store the minimum number of coins needed to make up each amount from 0 to amount.
    2. create a coin vector and store [2000,1000,500,200,100,50,20,10,5,2,1]
    
    3. Iterate across the coin array
        while(amount>=coin[i])
            amount=amount-coin[i];
            ans.push_back(coin[i]);

    4.return ans
        
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> func(int n){
    vector<int>ans;
    vector<int> coins={2000,1000,500,200,100,50,20,10,5,2,1};

    for(int i=0;i<coins.size();i++){
        while(n<coins[i]){
            n=n-coins[i];
            ans.push_back(coins[i]);
        }
    }
    return ans;
}

int main() {
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    vector<int> result = func(amount);

    if (result.empty()) {
        cout << "No coins can make up the amount." << endl;
    } else {
        cout << "Coins used to make up the amount: ";
        for (int coin : result) {
            cout << coin << " ";
        }
        cout << endl;
    }

    return 0;
}







