#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
Given an int array nums and an int target, find how many unique pairs in the array such that their sum is equal to target. Return the number of pairs.
aob
Example 1:

Input: nums = [1, 1, 2, 45, 46, 46], target = 47
Output: 2
Explanation:
1 + 46 = 47
2 + 45 = 47
Example 2:

Input: nums = [1, 1], target = 2
Output: 1
Explanation:
1 + 1 = 2
Example 3:

Input: nums = [1, 5, 1, 5], target = 6
Output: 1
Explanation:
[1, 5] and [5, 1] are considered the same.
*/ 

class Solution {
public:
    vector<int> uniquePair(vector<int> num, int target) {
        vector<int> res(2, -1);
        unordered_map<int, int> m;
        int curMax = INT_MIN;
        for(int i=0; i<num.size(); i++) {
            int toLook = target - 30 - num[i];
            if(m.count(toLook)) {
                if(max(i, m[toLook]) > curMax) {
                    curMax = max(i, m[toLook]);
                    res[0] = i;
                    res[1] = m[toLook];
                }
            }
            m[num[i]] = i;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> num1 = {10, 25,35, 60};
    int target1 = 90;
    
    vector<int> num2 = {20,50,40,25,30,10};
    int target2 = 90;
    
    vector<int> res1 = s.uniquePair(num1, target1);
    vector<int> res2 = s.uniquePair(num2, target2);
    for(int i:res1) cout<<i<<endl;
    cout<<"______\n";
    for(int i:res2) cout<<i<<endl;
    return 0;
}
