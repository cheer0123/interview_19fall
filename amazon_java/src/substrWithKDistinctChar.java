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

public class substrWithKDistinctChar {
    public static int atMostK(String s, int k) {
        int[] count = new int[256];
        int cnt = 0, i = 0, res = 0;
        for (int j = 0; j < s.length(); j++) {
            if (count[s.charAt(j)]++ == 0) cnt++;
            if (cnt > k) {
                while (--count[s.charAt(i++)] > 0);
                cnt--;
            }
            res = Math.max(res, j - i + 1);
        }
        return res;
    }

    public static int withK(String s, int k) {
        if(s.length() < k) return 0;
        return atMostK(s, k) - atMostK(s, k-1);
    }

    public static void main(String[] args) {
        System.out.println(withK("pqpqs",2));
        System.out.println(withK("aabab",3));
    }
}
