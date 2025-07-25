//131. Palindrome Partitioning

/*
    Problem Statement:
        Given a string s, partition s such that every substring of the partition is a palindrome. 
        Return all possible palindrome partitioning of s.
*/

/*
    we will use for loop and recursion to generate the partitions.  
    Approach:
    we will be using 3 functions:
        - isPalindrome: This function will be used to check if a string is a palindrome.
        - backtrack: This function will be used to generate the partitions.
        - partition: This function will be used to find the partitions by calling the backtrack function.

    partition :
    // parameters:
         - s: the input string.
    Logic:
        1. vector of vector of strings to store the partitions.

        2. vector of strings to store the current partition.

        3. call the backtrack function to generate the partitions.
        // backtrack(0, s, current, result):
        4. return the partitions.
    
    
    backtrack :
    // parameters:
        - start: the starting index of the string.
        - s: the input string.
        - current: the current partition being generated.
        - result: to store the final list of partitions.
    Logic:
        1. if start index is equal to the length of the string, it means we have found a valid partition.
            - push the current partition into the result.
            - return.
        2. for i from start to the end of the string:
            - if the substring s[start:i] is a palindrome:
                - push the substring into the current partition.
                - call the backtrack function with the next index.
                - pop the last element from the current partition (backtrack).
        3. return;

        isPalindrome:
    // parameters:
        - s: the input string.
        - start: the starting index of the string.
        - end: the ending index of the string.
    Logic:
        1. while start is less than end:
            - if s[start] is not equal to s[end], it is not a palindrome.
            - increment start and decrement end.
        2. return true if it is a palindrome.

*/

/*
    Time Complexity: O(2^n), where n is the length of the string. In the worst case, we may explore all possible partitions.
    Space Complexity: O(n), where n is the length of the string. The space is used for the recursion stack and to store the partitions.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> partition(string s){
    vector<vector<string>> result;
    vector<string> current;
    int n=s.length();
    backtrack(0, s, current, result);
    return result;

}

void backtrack(int start, const string &s, vector<string>& current, vector<vector<string>> &result){
    if(start==s.length()){
        result.push_back(current);
        return;
    }
    for(int i= start; i<s.length();i++){
        if(isPalindrome(s, start, i)){
            current.push_back(s.substr(start, i -start+1));
            backtrack(i+1, s, current, result);
            current.pop_back(); // backtrack
        }
    }
}

bool isPalindrome(const string &s, int start, int end){
    while(start < end){
        if(s[start] !=s[end]) return false;
        start++;
        end--;
    }
    return true;
}

int main() {
    string s = "aab";
    vector<vector<string>> result = partition(s);
    
    for(const auto& partition : result) {
        for(const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }
    
    return 0;
}