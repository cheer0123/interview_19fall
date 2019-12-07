#include <iostream>
#include <vector> 
#include <string>

using namespace std;

class Solution{
public:
    string reverseSetence(vector<char> s) {
        int i =0, n=s.size() -1;
        string res;
        string word;
        while(i <= n) {
            if(s[i] != ' ') {
                word += s[i];
                //cout<<word<<endl;
            } else {
                int len = word.size();
                res += word;
                word.clear();
            }
            i++;
        }
        for(int i=0; i<res.size(); i++) {
            ans += res[i];
        }
        return res;
    }
};

int main() {
    Solution s;
    string input = "I have annn dog";
    vector<char> s;
    for(int i=0; i<input.size(); i++) {
        s.push_back(input[i]);
    }
    string res;
    res = s.reverseSetence(s);
    cout<<res<<endl;
    return 1;
}