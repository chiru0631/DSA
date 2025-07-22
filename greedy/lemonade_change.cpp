// 860. Lemonade Change

/*
    Problem Statement:
        At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time 
        (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
        You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

        Note that you do not have any change in hand at first.

        Given an integer array bills where bills[i] is the bill the ith customer pays, 
        return true if you can provide every customer with the correct change, or false otherwise.
*/

/*
    Approach:
        1. Initialize 2 variables to keep track of the number of $5 and $10 bills you have.
        2. Iterate through each bill in the bills array:
            - If the bill is $5, increment the count of $5 bills.
            - If the bill is $10, check if you have a $5 bill to give as change. If yes, decrement the count of $5 bills and increment the count of $10 bills. If not, return false.
            - If the bill is $20, check if you can provide change using either one $10 bill and one $5 bill or three $5 bills. If neither option is available, return false.
*/

// Time Complexity: O(n), where n is the number of customers (length of the bills array).
// Space Complexity: O(1), since we are using a constant amount of space for the

#include <iostream>
#include <vector>
using namespace std;

bool lemonadeChange(vector<int>& bills){
    int fiveCount = 0, tenCount =0;
    for(int bill : bills){
        if(bill==5){
            fiveCount++;
        }else if(bill==10){
            if(fiveCount>0){
                fiveCount--;
                tenCount++;
            }else{
                return false;
            }
        }else if(bill==20){
            if(tenCount>0 && fiveCount>0){
                tenCount--;
                fiveCount--;
            }else if(fiveCount>=3){
                fiveCount -= 3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> bills = {5, 5, 10, 10, 20};
    
    if (lemonadeChange(bills)) {
        cout << "You can provide change to all customers." << endl;
    } else {
        cout << "You cannot provide change to all customers." << endl;
    }

    return 0;
}