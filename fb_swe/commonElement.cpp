#include <iostream>
#include <vector>

using namespace std;

// two araay are both sorted, no extra space
// running time O(m + n)
class Solution {
public:
    vector<int> findCommon(vector<int> nums1, vector<int> nums2) {
        vector<int> res;
        int i = 0, j =0;
        while(i < (int)nums1.size() && j < (int)nums2.size()) {
            if(nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
    
    // two araay are both sorted, no extra space
    // if array nums2  is very long
    // using binary search in long array
    // running time O(mlogn)
    vector<int> findCommon2(vector<int> nums1, vector<int> nums2) {
        int n = nums1.size();
        vector<int> res;
        for(int i=0; i<nums1.size(); i++) {
            vector<int> pos = searchRange(nums2, nums1[i]);
            int lenNums2 = pos[1] - pos[0];
            int lenNums1 = 0;
            while(i+1 < n && nums1[i] == nums1[++i]) lenNums1++;
            int cnt = min(lenNums1, lenNums2);
            for(int k = 0; k<cnt; k++) res.push_back(nums1[i]);
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // If A[mid] < target, then the range must begins on the right of mid (hence i = mid+1 for the next iteration)
        // If A[mid] > target, it means the range must begins on the left of mid (j = mid-1)
        // If A[mid] = target, then the range must begins on the left of or at mid (j= mid)
        // Since we would move the search range to the same side for case 2 and 3, we might as well merge them as one single case so that less code is needed:

        // 2*. If A[mid] >= target, j = mid;
        
        // test case: 5 7 7 8 8 10, target = 8;
        //            0 1 2 3 4 5     midIndex = 2 && 7 < 8   l = 3; mindex = 4, 8 == 8, l = 4, 
        // if use l <=r, l = m+1, r = m -1, will  casue dead lopp at 8
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        if (nums.empty()) {
            return ans;
        }
        int n = nums.size(), l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) l = m + 1;
            else r = m;
        }
        if (nums[l] != target) return ans;
        ans[0] = l;
        
        r = n - 1;
        while (l < r) {
            int m = l + (r - l + 1) / 2;
            if (nums[m] > target) r = m - 1;
            else l = m;
        }
        ans[1] = l;
        return ans;
    }
    
    void findCommonInTreeSortedArray(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3) { 
        int i = 0, j = 0, k = 0; 
        while (i < n1 && j < n2 && k < n3) { 
            // If x = y and y = z, print any of them and move ahead  
            // in all arrays 
            if (ar1[i] == ar2[j] && ar2[j] == ar3[k])  {   
                cout << ar1[i] << " ";   i++; j++; k++; 
            } 

            // x < y 
            else if (ar1[i] < ar2[j])  i++; 
            // y < z 
            else if (ar2[j] < ar3[k])  j++; 
            // We reach here when x > y and z < y, i.e., z is smallest 
            else k++; 
        }
    }
};