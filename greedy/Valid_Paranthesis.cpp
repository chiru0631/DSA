//678. Valid Parenthesis String

/*
Problem Statement:
    Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

    The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
*/

/*
Approach:
    1. Initialize 2 counters min and max to 0. // min tracks the minimum number of open parentheses, max tracks the maximum.
    2. Iterate through each character in the string s:
        - If the character is '(', increment both min and max.
        - If the character is ')', decrement both min and max.
        - If the character is '*', increment max and decrement min.
        - If at any point min becomes negative, reset it to 0 (as we cannot have negative open parentheses).
        - If max becomes negative, return false (as we cannot have more closing parentheses than opening ones).
    3. After iterating through the string, check if min is 0. If it is, return true (the string is valid). Otherwise, return false.

*/

/*
Complexity Analysis:
    - Time Complexity: O(n), where n is the length of the string s. We make a single pass through the string.
    - Space Complexity: O(1), we are using only a constant amount of space for the counters.
*/

#include <iostream>
#include <string>
using namespace std;

bool checkValidString(string s){
    int min=0,max=0;
    for(char c:s){
        if(c=='('){
            min++;
            max++;
        }
        else if(c==')'){
            min--;
            max--;
        }else{
            min--;
            max++;
        }
        if(min<0)min=0; // reset min to 0 if it goes negative
        if(max<0)return false; // if max goes negative, we have more closing parentheses than opening ones
    }
    return min==0; // if min is 0, all parentheses are matched
}

int main() {
    string s = "(*))";
    if (checkValidString(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }
    return 0;
}