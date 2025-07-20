//151. Reverse Words in a String

//Given an input string s, reverse the order of the words.
//A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
//Return a string of the words in reverse order concatenated by a single space.
//Note that s may contain leading or trailing spaces or multiple spaces between two words.
//The returned string should only have a single space separating the words. Do not include any extra spaces.

/*
Input: s = "the sky is blue"
Output: "blue is sky the"
*/



#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

/*
approach:
1. reverse the entire string
"the sky is blue" -> "eulb si yks eht"
2. reverse each word in the string
"eulb si yks eht" -> "blue is sky the"
3. remove extra spaces
*/

/*
time complexity: O(n)
space complexity: O(n)
*/

string reverseWord(string s){
    reverse(s.begin(),s.end());
    int n=s.size();
    string ans="";
    for(int i=0;i<n;i++){
        string word;
        while(i<n && s[i]!=' '){
            word+=s[i];
            i++;
        }
        if(word.size()>0){
            reverse(word.begin(),word.end());
            ans+=" "+word;
        }
    }
    return ans.substr(1);
};

int main() {
    string s = "the sky is blue";
    string result = reverseWord(s);
    printf("%s\n", result.c_str());
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/