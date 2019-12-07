#include <iostream>
#include <vector>

using namespace std;

class EqualSum {
public:
    int getindex(vector<int> &nums) {
        int sum  = 0, tem = 0;
        for(int i:nums) sum += i;
        for(int i=0; i<nums.size(); i++) {
            tem += nums[i];
            if(tem == sum/2) return i;
        }
        return -1;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(6);
    // nums.push_back(5);
    // nums.push_back(2);
    EqualSum es;
    cout<< es.getindex(nums)<<endl;
    return 1;
}