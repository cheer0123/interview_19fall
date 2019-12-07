#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    // m: len(s), n: len(t)
    string toEqual(string s, string t) {
        string res;
        if(s == t) return "EQUAL";
        int m = s.size(), n = t.size();
        if(m - n == 1) {
            if(s.substr(0, m-1)  == t) {
                res = "REMOVE ";
                res += s.back();
            }
        }
        if(n - m == 1) {
            if(s == t.substr(1, n-1)) {
                res = "INSERT ";
                res += t[0];
            }
        }
        else if(m == n) {
            int l = 0, r = n-1;
            while(l < r) {
                if(s[l] != t[l] || s[r] != t[r]) break;
                l++;
                r--;
            }
            if(l+1 == r && s[l] == t[r] && s[r] == t[l] && s[r] == t[l]) {
                res = "SWAP ";
                res += s[l] ;
                res += " ";
                res += s[r];
            } 
        }
    if(res.size() == 0) res = "IMPOSSIBLE";
    return res;
    }
};

int main() {
    Solution s;
    string res = s.toEqual("gain", "again");
    string res1 = s.toEqual("form", "from");
    string res2 = s.toEqual("form", "frrrrrrom");
    cout<<res<<endl;
    cout<<res1<<endl;
    cout<<res2<<endl;
}
