#include <iostream>
#include <string.h>

using namespace std; 

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        if(n1 > n2) {
            for(int i=0; i<n1; i++) {
                if(s[i] != t[i]) return s.substr(i+1) == t.substr(i);
            }
        } else if(n1 < n2) {
            for(int i=0; i<n2; i++) {
                if(s[i] != t[i]) return s.substr(i) == t.substr(i+1);
            }
        } else {
            for(int i=0; i<n1; i++) {
                if(s[i] != t[i]) return s.substr(i+1) == t.substr(i+1);
            }
        }
       return false;
    }
};

int main() {
    string a = "ab";
    string b = "abd";
    Solution s;
    if(s.isOneEditDistance(a, b)) cout<<"Is one edit distance!"<<endl;
    else cout<<"Not one edit distance!"<<endl;
    return 0;
}
