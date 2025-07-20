//13. Roman to Integer
/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/

/*
APPROACH:
1. create a map ds and store the roman numeral and it values
2. int ans=0
3. for(i=0 -> n-1)
    if(s[i] is less than s[i+1]) ans-=ds[s[i]]
    else ans+=ds[s[i]];
*/

#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

int romantoint(string s){
    int n=s.size();
    if(n==0) return 0;
    unordered_map<char,int> mpp;
    mpp['I']=1;
    mpp['V']=5;
    mpp['X']=10;
    mpp['L']=50;
    mpp['C']=100;
    mpp['D']=500;
    mpp['M']=1000;

    int res=0;
    for(int i=n-1;i>=0;i--){
        if(i<n-1 && mpp[s[i]]<mpp[s[i+1]]){
            res=res-mpp[s[i]];
        }else{
            res+=mpp[s[i]];
        }
    }
    return res;
}

int main(){
    string s = "MCMXCIV";
    int result = romantoint(s);
    printf("%d\n", result); // Output: 1994
}

/*
time complexity: O(n)
space complexity: O(1)
*/