#include <iostream>
#include <string.h>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int claculator1(string input) {
        int res = 0, sign = 1, n = input.size();
        for(int i=0; i<n; i++) {
            char c = input[i];
            if(c == '+') sign = 1;
            else if(c == '-') sign = -1;
            else if(c >= '0') {
                int num  = 0;
                while(i<n && input[i] >= '0') {
                    num = 10*num + input[i++] - '0';
                }
                res += sign * num;
                --i;
            }
        }
        return res;
    }
    
    int claculator2(string input) {
        int res = 0, sign = 1, n = input.size();
        stack<int> st;
        for(int i=0; i<n; i++) {
            char c  = input[i];
            if(c == '+') sign = 1;
            else if(c == '-') sign = -1;
            else if(c >= '0') {
                int num = 0;
                while(i < n && input[i] >= '0') {
                    num += num*10 + input[i++] - '0';
                }
                res += num * sign;
                i--;
            } else if(c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if( c == ')') {
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        return res;
    }
    
    int claculator2(string input, unordered_map<char, int> dict) {
        int res = 0, sign = 1, n = input.size();
        stack<int> st;
        for(int i=0; i<n; i++) {
            if(input[i] == '+') sign = 1;
            else if(input[i] == '-') sign = -1;
            else if(input[i] >= '0') {
                int num = 0;
                while(i<n && input[i] >= '0') {
                    if(input[i] >= '0' && input[i] <= '9') {
                        num = num * 10 + input[i] - '0';
                    } else {
                        if(dict.count(input[i])) num += num * 10 + dict[input[i]];
                    }
                }
            } else if(input[i] == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if(input[i] == ')'){
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int c1 = s.claculator1("1 - 3 + 4 - 5");
    int c2 = s.claculator2("(1-(4+5+2)-3)+(6+8)");
    int c2 = s.claculator2("(1-(4+5+2)-1)+(6+8)");
    cout<<"c1: "<<c1<<endl;
    cout<<"c2: "<<c2<<endl;
    return 1;
}