#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution{
public:
    string diverse(int A, int B, int C) {
        vector<char> res;
        priority_queue<pair<int, char> > pq;
        pq.push(make_pair(A, 'a'));
        pq.push(make_pair(B, 'b'));
        pq.push(make_pair(C, 'c'));
        // int total = A + B + C;
        // char pre = "";
        while(!pq.empty()) {
            vector<char> used;
            int curCnt = pq.top().first;
            char curChar =  pq.top().second;
            pq.pop();
            int size = res.size();
            if(size >= 2 && curChar == res[size] && curChar == res[size-1]) {
                if(pq.empty()) break;
                int temCnt = pq.top().first;
                char temChar =  pq.top().second;
                pq.pop();
                res.push_back(temChar);
                temCnt--;
                if(temCnt> 0) pq.push(make_pair(temCnt, temChar));
            } else {
                res.push_back(curChar);
                curCnt--;
            }
            if(curCnt> 0) pq.push(make_pair(curCnt, curChar));
        }
        string ans;
        for(char c:res) ans += c;
        return ans;
    }
};

int main() {
    Solution s;
    string res = s.diverse(6,1,1);
    cout<<res<<endl;
}