#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        vector<string> m;
        istringstream in(S);
        string word, res;
        string appd = "maa";
        while(in >> word) {
            if(!isVowel(word[0])) {
                word.push_back(word[0]);
                word = word.substr(1);
            }
            word += appd;
            res += word + " ";
            appd += "a";
        }
        return res.substr(0, res.size()-1);
    }
    
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u');
    }
};

int main() {
        string s = "I speak Goat Latin";
        Solution m;
        cout << "The coverted Latin is:" << endl;
        cout << m.toGoatLatin(s) << endl;
        return 0;
}

