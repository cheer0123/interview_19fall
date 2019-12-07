#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // find continuous subarray sum equals the target ，
    vector<int> subarraySum(vector<int> A, int sum) {
        vector<int> res;
        for(int i=0; i<A.size(); i++) {
            int tem = A[i];
            for(int j=i+1; j<A.size(); j++) {
                tem += A[j];
                if(tem == sum) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
    
    
    // Given an array of integers and an integer k, you need to find the total number of 
    // continuous subarrays whose sum equals to k.
    int subarraySumNum (vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return 0;
        int sum = 0, res = 0;
        unordered_map<int, int> m;
        m[0]++;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            if(m.count(sum-k)) res+= m[sum-k];
            m[sum]++;
        }
        return res;
    }

    //sum of contiguous subarray within a  array of numbers which has the largest sum.
    // negative element
    int maxSubArraySum(int a[], int size) { 
        int max_so_far = INT_MIN, sum = 0; 

        for (int i = 0; i < size; i++)  { 
            sum += a[i]; 
            if (max_so_far < sum) 
                max_so_far = sum; 
            if (sum < 0) 
                sum = 0; 
        }
        return max_so_far; 
    } 
};

int main() {
	//code
    Solution s;
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(7);
    input.push_back(5);
    vector<int> res = s.subarraySum(input, 12);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}