//686. Repeated String Match

/*
    Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it.
    If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

    Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".
*/

/*
Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

*/

/*
Approach:
1. Find the lengths of a and b
2. int n=a.size(), m=b.size();
3. int count=m/n;
4. cnt =count;
5. declare a string res and initialize it with ""

6. while(cnt--){
    res=res+a;

}
7. if(res.find(b)!=string::npos) return count;

 res=res+a;
8. if(res.find(b)!=string::npos) return count+1;
9. res=res+a;
10. if(res.find(b)!=string::npos) return count+2;
*/

/*
    Pattern to find the minimum number of times to repeat string a:
    String Matching with Bounded Search Pattern

        Core Pattern Components:
            Mathematical Estimation: Calculate minimum possible repetitions (k = m/n)
            Incremental Building: Build the repeated string step by step
            Bounded Search: Check only k, k+1, and k+2 repetitions (not infinite)
            Substring Search: Use built-in string search (find() method)

*/

/*
Alternative Patterns for this problem:
KMP Algorithm: More efficient substring search
*/

/*
 time complexity: O(n*m) where n is the length of a and m is the length of b
 space complexity: O(n) for the string res
*/


#include <stdio.h>
#include <string>
using namespace std;

int repstr(string a, string b) {
    int n=a.size();
    int m=b.size();
    int k=m/n;
    int cnt=k;
    string res="";
    while(cnt--){
        res=res+a;
    }
    if(res.find(b)!=string::npos) return k;
    res=res+a;
    if(res.find(b)!=string::npos) return k+1;
    res=res+a;
    if(res.find(b)!= string::npos) return k+2;
    return -1;
}

int main() {
    string a = "abcd";
    string b = "cdabcdab";
    int result = repstr(a, b);
    printf("%d\n", result); // Output: 3
    return 0;
}


/*
optimal solution:
//686. Repeated String Match - KMP Implementation

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

// KMP preprocessing - build failure function (LPS array)
vector<int> buildLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;  // length of previous longest prefix suffix
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP search function
int kmpSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    
    if (m == 0) return 0;
    if (n < m) return -1;
    
    vector<int> lps = buildLPS(pattern);
    
    int i = 0;  // index for text
    int j = 0;  // index for pattern
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            return i - j;  // found pattern at index i-j
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;  // pattern not found
}

int repstrKMP(string a, string b) {
    int n = a.size();
    int m = b.size();
    
    if (m == 0) return 0;
    if (n == 0) return -1;
    
    // Check if all characters in b exist in a
    bool charExists[256] = {false};
    for (char c : a) {
        charExists[c] = true;
    }
    for (char c : b) {
        if (!charExists[c]) return -1;
    }
    
    // Calculate minimum possible repetitions
    int k = (m + n - 1) / n;  // ceiling division
    
    // Try k and k+1 repetitions using KMP
    for (int rep = k; rep <= k + 1; rep++) {
        string repeated = "";
        for (int i = 0; i < rep; i++) {
            repeated += a;
        }
        
        if (kmpSearch(repeated, b) != -1) {
            return rep;
        }
    }
    
    return -1;
}

int main() {
    string a = "abcd";
    string b = "cdabcdab";
    int result = repstrKMP(a, b);
    printf("%d\n", result); // Output: 3
    return 0;
}

/*
KMP Algorithm Benefits:
1. Time Complexity: O(n + m) for search vs O(n*m) for naive
2. Space Complexity: O(m) for LPS array
3. Avoids redundant character comparisons
4. Efficient for large strings and multiple searches

How LPS works:
- For pattern "ABAB": LPS = [0, 0, 1, 2]
- When mismatch occurs, jump to LPS[j-1] position
- This skips unnecessary comparisons
*/