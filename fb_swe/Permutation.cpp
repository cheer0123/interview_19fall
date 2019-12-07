#include <iostream>
#include <vector> 

using namespace std;

// leetcode 567 &&  leetcode 438
class Solution {
public:
    vector<string> permutation(string s) {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        int n1 = s.size(), n2 = s2.size();
        if(n2 < n1) return false;
        for(int i=0; i<n1; i++) {
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        if(v1 == v2) return true;
    }
};