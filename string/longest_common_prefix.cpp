//14. Longest Common Prefix

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

/*
Approach:
1.take the size of the array
2. if size is 0 return ""
3. sort the array
4. take the first and last string
5. take the minimum length of the first and last string
6. compare the characters of the first and last string up to the minimum length
7. return the common prefix
*/


/*

    pattern to find the longest common prefix:
    Sorting-based Two Pointer Pattern

        Key Pattern Elements:
            Sort the array first - This is the crucial insight
            Compare only the first and last strings after sorting
            Character-by-character comparison until mismatch

*/

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string lsp(vector<string>& strs) {
    int n=strs.size();
    if(n==0) return "";
    sort(strs.begin(),strs.end());
    string first=strs[0];
    string last=strs[n-1];
    int i=0;
    while(i<first.size() && i<last.size()){
        if(first[i]!=last[i]) break;
        i++;
    }
    return first.substr(0,i);
}

int main(){
    vector<string> strs = {"flower", "flow", "flight"};
    string result = lsp(strs);
    printf("%s\n", result.c_str()); // Output: "fl"
    return 0;
}

/*
time complexity: O(nlogn) for sorting the array
space complexity: O(1) for storing the result
*/