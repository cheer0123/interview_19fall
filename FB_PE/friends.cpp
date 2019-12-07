#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res = 0, n = ages.size();
        vector<int> count(121, 0);
        for(int i:ages) {
            count[i]++;
        }
        for(int i=1; i<121; i++) {
            count[i] += count[i-1];
        }
        
        for(int age:ages) {
            res += max(0, count[age] - count[age/2+7] -1);  //people will not friend request themselves, so  - numInAge[i]
        }
        return res;
    }
};