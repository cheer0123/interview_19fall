#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
*/ 

class Solution{
public:
    string longestPalindrome(string s) {
        // dp[i, j] := wether or not s[j...i] is palindrome
        int n = s.size();
        int len = 0, index = 0;
        vector<vector<bool>> isP(n, vector<bool>(n, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                if(s[j] == s[i] && (i- j<2 || isP[j+1][i-1])) {
                    isP[j][i] = true;
                    if(i-j+1 > len) {
                        len = i-j+1;
                        index = j;
                    }
                }
            }
        }
        return s.substr(index, len);
    }
};

int main() {
    Solution s;
    string res1 = s.longestPalindrome("babad");
    string res2 = s.longestPalindrome("cbbd");
    cout<<res1<<endl;
    cout<<res2<<endl;
    return 0;
}