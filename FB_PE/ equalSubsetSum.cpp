#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0, n = nums.size();
        for(int i:nums) sum += i;
        if(sum %2 != 0) return false;
        // 0- 1 snapkacp
        // dp[j] := whether can compose j given nums[0....i];
        // base case: dp[0], 0 element compose value 0;
        vector<bool> dp(sum/2+1, false);
        dp[0] = true;
        for(int num : nums) {
            for(int j=sum/2; j>=num; j--) {
                dp[j] = dp[j] || dp[j-num];
            }
        }
        return dp[sum/2];
    }
};