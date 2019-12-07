#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int l=0, r = s.size() -1;
        while(l<=r) {
            while(!isalnum(s[l]) && l < r) l++;
            while(!isalnum(s[r]) && l < r) r--;
            if(s[l] != s[r]) return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    if(s.isPalindrome("A man, a plan, a canal: Panama")) {
        cout<<"is valid P" << endl;
    } else cout<<"not valid P" << endl;
    return 0;
}