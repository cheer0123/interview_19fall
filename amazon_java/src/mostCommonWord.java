

/*
https://leetcode.com/problems/most-common-word/


Given a paragraph and a list of banned words, return the most frequent word
that is not in the list of banned words.  It is guaranteed there is at least one
word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.
Words in the paragraph are not case sensitive.  The answer is in lowercase.
*/

import java.util.*;

/*
https://leetcode.com/problems/most-common-word/


Given a paragraph and a list of banned words, return the most frequent word
that is not in the list of banned words.  It is guaranteed there is at least one
word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.
Words in the paragraph are not case sensitive.  The answer is in lowercase.
*/

public class mostCommonWord {
    public static String mostCommon(String paragraph, String[] banned) {
        for(String s:banned) s.toLowerCase();
        Set<String> bannedSet = new HashSet<>(Arrays.asList(banned));
        Map<StringBuilder, Integer> m = new HashMap<>();
        //String[] words = paragrap.replaceAll("\\W+" , " ").toLowerCase().split("\\s+");
        StringBuilder word = new StringBuilder();
        paragraph += ' ';
        for(char ch : paragraph.toCharArray()) {
            if (ch >= 'A' && ch <= 'Z') {
                word.append((char)(ch + 'a' - 'A'));
            } else if(ch >= 'a' && ch <= 'z') {
                word.append(ch);
            }  else {
                if(ch <'a' || ch > 'z') {
                    if(!bannedSet.contains(word) && word.length() > 0) {
                        if(m.containsKey(word)) m.put(word, m.get(word) + 1);
                        else  m.put(word, 1);
                    }
                }
            }
        }
        String res = "";
        int cnt = -1;
        for(Map.Entry<StringBuilder, Integer> entry: m.entrySet()) {
            if(entry.getValue() > cnt) {
                res = entry.getKey().toString();
                cnt = entry.getValue();
            }
        }

        return res;
    }

    public static String mostCommonWord(String paragraph, String[] banned) {
        String[] words = paragraph.toLowerCase().split("[ !?',;.]+");
        HashMap<String, Integer> map = new HashMap<>();
        for(String word : words) map.put(word, map.getOrDefault(word, 0) + 1);
        for(String word : banned) if(map.containsKey(word)) map.remove(word);
        String res = null;
        for(String word : map.keySet())
            if(res == null || map.get(word) > map.get(res))
                res = word;
        return res;
    }

    public static void main(String[] args) {
        String paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
        String[] banned;

        banned = new String[]{"hit"};
        //bug!!!!!
        System.out.println(mostCommon(paragraph, banned));

        System.out.println(mostCommonWord(paragraph, banned));
    }
}
