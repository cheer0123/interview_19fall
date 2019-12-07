#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/*
Given a string s and an int k, return an int representing the number of substrings (not unique) of s 
with exactly k distinct characters. If the given string doesn't have k distinct characters, return 0.
https://leetcode.com/problems/subarrays-with-k-different-integers

Example 1:

Input: s = "pqpqs", k = 2
Output: 7
Explanation: ["pq", "pqp", "pqpq", "qp", "qpq", "pq", "qs"]
Example 2:

Input: s = "aabab", k = 3
Output: 0
Constraints:

The input string consists of only lowercase English letters [a-z]
0 ≤ k ≤ 26
*/

class Solution {
public:
    int substrWithKDistinctChar(string s, int k) {
        if(k > s.size()) return 0;
        return atMostK(s, k) - atMostK(s, k-1);
    }
    // all subarrays with <= K distinct numbers are counted.
    int atMostK(string s, int k) {
        int res = 0, cnt = 0, left = 0;
        unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++) {
            if(m[s[i]] == 0) cnt++;
            m[s[i]]++;
            while(cnt > k) {
                if(--m[s[left]] == 0) cnt--;
                left++;
            }
            res += i - left + 1;
        }
        return res;
    }
};

int main() {
    Solution s;
    int res = s.substrWithKDistinctChar("pqpqs", 2);
    cout<<res<<endl;
    return 0;
}