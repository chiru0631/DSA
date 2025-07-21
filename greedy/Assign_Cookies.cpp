//455. Assign Cookies

/*
    Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

    Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with;
    and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
    Your goal is to maximize the number of your content children and output the maximum number.
*/

/*
    Pattern Used: Greedy

    Approach:
    1. Sort both the greed factor array and the cookie size array.
       - sort(g.begin(), g.end());
       - sort(s.begin(), s.end());
    2. Initialize two pointers, one for the greed factor array and one for the cookie size array.
       - int i = 0, j = 0;
    3. Iterate through both arrays:
       - while (i < g.size() && j < s.size()) {
    4. If the current cookie size is greater than or equal to the current child's greed factor,
          - Increment the content children count and move to the next child and next cookie.
          - i++;
          - j++;
       }
    }
         - else {
             - If the current cookie size is less than the current child's greed factor, move to the next cookie.
             - j++;
         }
    5. Return the count of content children.

*/

/*
    Time Complexity: O(n log n + m log m), where n is the number of children and m is the number of cookies.
    Space Complexity: O(1), as we are using only a few extra variables.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>&g ,vector<int>&s){
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int i=0,j=0;
    int contentChildren = 0;
    while(i<g.size() && j<s.size()){
        if(s[j]>=g[i]){
            contentChildren++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    return contentChildren;
}

int main() {
    vector<int> g = {1, 2, 3}; // greed factors of children
    vector<int> s = {1, 1}; // sizes of cookies
    cout << "Maximum number of content children: " << findContentChildren(g, s) << endl;
    return 0;
}