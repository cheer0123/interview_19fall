#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int rotateMax(int A) {
        string B = to_string(A);
        int n = B.length();
        int  i = 0;
        while(i < n) {
            if(B[i] == '6') break;
            i++;
        }
        if(i == n) return A;
        string res = B.substr(0, i) + '9' + B.substr(i+1);
        return stoi(res);
    }
};

int main() {
    Solution s;
    int res  = s.rotateMax(699);
    cout<<res<<endl;
    return 1;
}