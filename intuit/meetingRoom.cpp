#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
class Solution {
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty() || intervals[0].empty()) return res;
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for(int i=1; i< intervals.size(); i++) {
            if(res.back()[1] >= intervals[i][0]) {
               res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else res.push_back(intervals[i]);
        }
        return res;
    }
};

class Solution {
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0]<b[0];
    }
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size()<2) return true;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i=1; i<intervals.size(); i++) {
            if (intervals[i][0] < intervals[i-1][1]) 
                return false;
        }
        return true;
    }
};