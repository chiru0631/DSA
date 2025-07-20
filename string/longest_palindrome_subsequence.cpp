//516. Longest Palindromic Subsequence

/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence 
by deleting some or no elements without changing the order of the remaining elements.
*/

/*
approach:
1. first find the length of the give string
check if the string is empty or not
2. init start=0 and maxlen=1
3. for(i=0 -> n-1)
// odd length
low=i, high=i
while(low>=0 && high<n && s[low]==s[high]){
    if(high-low+1>maxlen){
        start=low;
        maxlen=high-low+1;
    }
    low--;
    high++;
}
// even length
low=i, high=i+1
while(low>=0 && high<n && s[low]==s[high]){
    if(high-low+1>maxlen){
        start=low;
        maxlen=high-low+1;
    }
    low--;
    high++;
}
*/

/*
Time complexity: O(n^2)
Space complexity: O(1)

*/

#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int longpalsubseq(string s){
    int n=s.size();
    if(n==0) return 0;
    int start=0,maxlen=1;
    for(int i=0;i<n;i++){
        //odd length
        int low=i,high=i;
        while(low>=0 && high<n && s[low]==s[high]){
            if(high-low+1>maxlen){
                start=low;
                maxlen=high-low+1;
            }
            low--;
            high++;
        }
        //even length
        low=i,high=i+1;
        while(low>=0 && high<n && s[low]==s[high]){
            if(high-low+1>maxlen){
                start=low;
                maxlen=high-low+1;
            }
            low--;
            high++;
        }
    }
    return maxlen;
}

int main(){
    string s = "babad";
    int result = longpalsubseq(s);
    printf("%d\n", result);
    return 0;
}