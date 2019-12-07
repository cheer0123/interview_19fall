class Solution(object):
    def uniqueMorseRepresentations():
        words =  ["gin", "zen", "gig", "msg"]
        MORSE = [".-","-...","-.-.","-..",".","..-.","--.",
                 "....","..",".---","-.-",".-..","--","-.",
                 "---",".--.","--.-",".-.","...","-","..-",
                 "...-",".--","-..-","-.--","--.."]

        seen = ("".join(MORSE[ord(c) - ord('a')] for c in word)
                for word in words)

        print(len(seen))
    uniqueMorseRepresentations()