/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
*/

public class longestPalindrome {
    public static String longestP(String s) {
        int n = s.length();
        int start = 0, len = 0;
        String res = "";
        boolean[][] dp = new boolean[n][n];

        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                if(s.charAt(i) == s.charAt(j)) {
                    if(i-j < 2 || dp[j+1][i-1]) {
                        dp[j][i] = true;
                        if(len < i-j +1) {
                            len = i - j + 1;
                            start = j;
                        }
                    }
                }
            }
        }
        return s.substring(start, start+len);
    }

    public static void main(String[] args) {
        String s1 = "babad";
        String s2 = "cbbd";

        System.out.println(longestP(s1));
        System.out.println(longestP(s2));
    }
}
