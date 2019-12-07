import java.util.HashMap;
import java.util.Map;

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
class Main {
    public static int findUniquePairs(int[] nums, int target) {
        Map<Integer, Boolean> prev = new HashMap<>();
        int pairs = 0;
        for (int i = 0, n = nums.length; i < n; ++i) {
            int diff = target - nums[i];
            if (prev.containsKey(diff)) {
                if (!prev.get(diff)) {
                    ++pairs;
                    prev.put(diff, true);
                }
                prev.put(nums[i], true);
            } else {
                prev.put(nums[i], false);
            }
        }
        return pairs;
    }


    public static void main(String[] args) {
        int[] nums1 = {1, 1, 2, 45, 46, 46};
        int target1 = 47;
        System.out.println(findUniquePairs(nums1, target1));
        int[] nums2 = {1, 1};
        int target2 = 2;
        System.out.println(findUniquePairs(nums2, target2));
    }
}
