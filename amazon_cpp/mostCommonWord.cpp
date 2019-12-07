#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
https://leetcode.com/problems/most-common-word/


Given a paragraph and a list of banned words, return the most frequent word 
that is not in the list of banned words.  It is guaranteed there is at least one 
word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  
Words in the paragraph are not case sensitive.  The answer is in lowercase.
*/


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        unordered_set<string> bannedSet;
        bannedSet.insert(banned.begin(), banned.end());
        string word;
        paragraph += ' ';
        for(int i=0; i<paragraph.size(); i++) {
            if(paragraph[i] >='A' && paragraph[i] <='Z') 
                paragraph[i] = paragraph[i] + 32;
            if(paragraph[i] <'a' || paragraph[i] >'z') {
                if(bannedSet.find(word) == bannedSet.end() 
                   && word.size() > 0) {
                    m[word]++;
                }
                word.clear(); 
            } else word += paragraph[i];
        }
        string res;
        int cnt = INT_MIN;
        for(auto p:m) {
            if(p.second > cnt) {
                res = p.first;
                cnt = p.second;
            }
        }
        return res;
    }
};

