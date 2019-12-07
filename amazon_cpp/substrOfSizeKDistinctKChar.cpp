#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<string> substr_of_sizeK_with_K_distict_char (string s, int k) {
        unordered_set<string> res;
        for(int i=0; i<s.size()-k + 1; i++) {
            string sub;
            unordered_set<char> sub_dic;
            for(int j=i; j<i+k; j++) {
                if(sub_dic.count(s[j]) ) break;
                else {
                    sub_dic.insert(s[j]);
                    sub += s[j];
                }
            }
            
            if(sub.size() == k) {
                // cout<<sub<<" "<<sub.size()<<endl;
                // for(char c:sub) cout<<c<<endl;
                res.insert(sub);
            }
        }
        return res;
    }
};

int main () {
    Solution s;
    unordered_set<string> res1 = s.substr_of_sizeK_with_K_distict_char("abcabc", 3);
    unordered_set<string> res2 = s.substr_of_sizeK_with_K_distict_char("abacab", 3);
    unordered_set<string> res3 = s.substr_of_sizeK_with_K_distict_char("awaglknagawunagwkwagl", 4);
    for(string s:res1)  cout<<s<<endl;
    cout<<"___\n";
    for(string s:res2)  cout<<s<<endl;
    cout<<"___\n";
    for(string s:res3)  cout<<s<<endl;
    return 0;
}