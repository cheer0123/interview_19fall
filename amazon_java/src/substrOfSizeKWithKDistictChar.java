import java.util.HashSet;
import java.util.LinkedHashSet;

/*
Given a string s and an int k, return all unique substrings
of s of size k with k distinct characters.

        Example 1:

        Input: s = "abcabc", k = 3
        Output: ["abc", "bca", "cab"]
*/

public class substrOfSizeKWithKDistictChar {
    public static HashSet<String> uniqueSubstringSizeK(String s, int k){
        HashSet<String> set = new HashSet<>();
        for(int i =0;i<s.length()-k+1;i++) {
            StringBuilder sb = new StringBuilder();
            String st = "";
            for(int j=i;j<i+k;j++) {
                if(st.indexOf(s.charAt(j))!=-1) {
                    break;
                }
                else {
                    st = st+s.charAt(j);
                }
            }
            if(st.length()==k){
                set.add(st);
            }
        }
        return set;
    }

    public static void main(String[] args) {
        HashSet<String> res1 = uniqueSubstringSizeK("abcabc", 3);
        HashSet<String> res2 = uniqueSubstringSizeK("abacab", 3);
        HashSet<String> res3 = uniqueSubstringSizeK("awaglknagawunagwkwagl", 4);
        System.out.println(res1);
        System.out.println(res2);
        System.out.println(res3);
    }
}
