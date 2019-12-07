import java.util.Arrays;
import java.util.HashMap;


/*
Given a list of positive integers nums and an int target, return indices of the two numbers such that they add up to a target - 30.

Conditions:

You will pick exactly 2 numbers.
You cannot pick the same element twice.
If you have muliple pairs, select the pair with the largest number.
Example 1:

Input: nums = [1, 10, 25, 35, 60], target = 90
Output: [2, 3]
Explanation:
nums[2] + nums[3] = 25 + 35 = 60 = 90 - 30
Example 2:

Input: nums = [20, 50, 40, 25, 30, 10], target = 90
Output: [1, 5]
Explanation:
nums[0] + nums[2] = 20 + 40 = 60 = 90 - 30
nums[1] + nums[5] = 50 + 10 = 60 = 90 - 30
You should return the pair with the largest number.
*/

public class findPairWithGivenSum {
    public static int[] findPair(int[] num, int sum) {
        HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
        int[] res = new int[2];
        int curMax = Integer.MIN_VALUE;
        for(int i=0; i<num.length; i++) {
            if(m.containsKey(sum-num[i])) {
                if(num[i] > curMax || sum - num[i] > curMax) {
                    res[0] = i;
                    res[1] = m.get(sum - num[i]);
                    curMax = Math.max(num[i], sum - num[i]);
                }
            }
            m.put(num[i], i);
        }
        return res;
    }



    public static void main(String[] args) {
        int[] nums1 = {1, 10, 25, 35, 60};
        int target1 = 90;
        System.out.println(Arrays.toString(findPair(nums1, target1-30)));
        int[] nums2 = {20, 50, 40, 25, 30, 10};
        int target2 = 90;
        System.out.println(Arrays.toString(findPair(nums2, target2-30)));
        int[] nums3 = {50, 20, 10, 40, 25, 30};
        int target3 = 90;
        System.out.println(Arrays.toString(findPair(nums3, target3-30)));
    }
}
