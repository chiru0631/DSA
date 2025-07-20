//8. String to Integer (atoi)

/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").

Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.

Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached.
If no digits were read, then the result is 0.

Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1],
then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231,
and integers greater than 231 - 1 should be rounded to 231 - 1.

Return the integer as the final result.
*/

/*
Approach:
i=0, sign=1, result=0
1. Skip leading whitespace
while (i < s.size() && s[i] == ' ') i++;
2. Check for sign
if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
    sign = (s[i] == '-') ? -1 : 1;
    i++;
}
3. Convert digits
while (i < s.size() && isdigit(s[i])) {
    int digit = s[i] - '0';
    if (result > (INT_MAX - digit) / 10) {
        // Handle overflow
        return (sign == 1) ? INT_MAX : INT_MIN;
    }
    result = result * 10 + digit;
    i++;
}
4. Handle overflow
if (result > INT_MAX) {
    return (sign == 1) ? INT_MAX : INT_MIN;
}
*/

#include<stdio.h>
#include<string>
#include<limits.h>
using namespace std;

int Atoi(string s){
    int i=0,sign=1,result=0;
    // Skip leading whitespace
    while(i<s.size() && s[i]==' ') i++;


    // Check for sign
    if(i<s.size() && (s[i]=='-' || s[i]=='+')){
        sign=(s[i]=='-')?-1:1;
        i++;
    }



    //convert digits
    while(i<s.size() && isdigit(s[i])){
        int digit=s[i]-'0';
        //handle overflow
        if(result>(INT_MAX-digit)/10){
            return (sign==1)?INT_MAX:INT_MIN;
        }
        result=result*10+digit;
        i++;
    }


    //handle overflow
    if(result>INT_MAX){
        return (sign==1)?INT_MAX:INT_MIN;
    }
    return result*sign;

}

int main(){
    string s = "   -42";
    int result = Atoi(s);
    printf("%d\n", result); // Output: -42
}

/*
time complexity: O(n), where n is the length of the string
space complexity: O(1), since we are using a constant amount of space for variables
*/
