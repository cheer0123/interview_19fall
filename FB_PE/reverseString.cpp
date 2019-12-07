#include <iostream>
#include <string>
#include <vector>

using namespace std;

// String Rotate & 给两个数i和j,要求翻转index i to index j之间的substring
// reverse(v.begin() + 5, v.begin() + 8);
// applied reverse() on the vector from index 5 to index 7
class Solution1 {
public:
    string rotateString(string s, int left, int right) {
        reverse(s.begin() + left, s.begin() + right + 1);
        return s;
    }
};

// Given an array, rotate the array to the right by k steps
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int n= nums.size();
        // intial :  1  2  3  4  5  6  7   k= 3
        // Step1:    4  3  2  1  5  6  7  
        // Step2:    4  3  2  1  7  6  5
        // Step3:    5  6  7  1  2  3  4
        // n == 7, k == 3, n - k == 4
        reverse(nums.begin(), nums.begin()+n-k); // index 0 ~ 3
        reverse(nums.begin()+n-k, nums.end());   // index 4 ~ 6
        reverse(nums.begin(), nums.end());      // index 0 ~ 6
    }
};

int main() {
    Solution1 solu1;
    Solution2 solu2;
    cout<<solu1.rotateString("1234567", 3, 5)<<endl;;
}

