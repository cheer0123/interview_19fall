#include <iostream>
#include <vector>

using namespace std;
class Solution {
    vector<vector<int> > dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
public:
bool canReach(vector<vector<int > > &board,  vector<int > pos) {
    dfs(board, pos[0], pos[1]);
    for(int i = 0; i< board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            if(board[i][j] == 0) return false;
        }
    }
    return true;
}

void dfs(vector<vector<int > > &board, int i, int j) {
    if(board[i][j] == 1 || board[i][j] == -1
        || i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) 
        return;
    board[i][j] = 1;
    for(auto d:dirs) {
        int x = i+d[0], y = j + d[1];
        dfs(board, x, y);
    }
}

void shortestDistHelper(vector<vector<int > > &board, int i, int j, vector<int> end, vector<int> &res, int cur) {
    if(i == end[0] && j == end[1]) {
        res.push_back(cur);
        return;
    }
    
    for(auto d:dirs) {
        int x = i+d[0], y = j + d[1];
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != 1) continue;
        shortestDistHelper(board, x, y, end, res, cur++);
    }
}

int shortestDist(vector<vector<int > > &board, vector<int> start, vector<int> end) {
    vector<int> dist;
    int res = INT_MAX;
    shortestDistHelper(board, start[0], start[1], end, dist, 0);
    for(int i:dist) {
        if(i < res) res = i;
    }
    return res;
}


};

int main() {
    Solution s;
    vector<int > a;
    a.push_back(0);
    a.push_back(-1);
    a.push_back(0);
    a.push_back(0);
    vector<int > b;
    a.push_back(0);
    a.push_back(1);
    a.push_back(-1);
    a.push_back(0);
    vector<int > c;
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    vector<vector<int > > board;
    board.push_back(a);
    board.push_back(b);
    board.push_back(c);
    // vector<vector<int > > board{ { 0,-1,0,0 }, { 0,1,-1,0 }, { 0,1,0,0 } };
    vector<int > pos;
    pos.push_back(0);
    pos.push_back(0);
    if(s.canReach(board, pos)) cout<<"can reach"<<endl;
    else cout<<"can't reach"<<endl;
    return 1;
}