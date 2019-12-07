#include <iostream> 
#include <vector> 


class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> isP(n, vector<bool>(n, false));
        int cnt = 0;
        // isP[0][0] = true;
        for(int i=0; i<n; i++) {
            // cnt++; 
            for(int j=0; j<=i; j++) {
                if(s[j] == s[i] && (i-j < 2 || isP[j+1][i-1])) {
                    isP[j][i] = true;
                    if(isP[j][i]) cnt++;
                }
            }
        }
        return cnt;
    }
};