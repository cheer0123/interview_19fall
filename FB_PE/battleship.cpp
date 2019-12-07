#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// 一个N*N的grid, 里面battleship‍‍‍‍‌‌‌‍‌‍‍‌‍‍‍‌‍‌‌是一个横着或者竖着的一条线（三个格子）， 
// 要找到battleship的坐标 可以每次隔3个格子 按行扫、按列扫，输出坐标需要输出battleship的三个格子的各自坐标...

// 实在一个square里面找battership的位置，battership会连续占据三个的位置，或是横着或是竖着。
// 里面会有一个给定函数来判断给定位置是不是有船，最后要求输出battership占据三个位置的坐标。
// Battleship game: write a function that finds a ship and return its coordinates.

// 思路: 首先判断前后左右，如果是有船，就添加。其次再扫描3 * 3 格，找到所有的坐标

class Battleboard {
public:
set<pair<int, int> > getships(vector <vector <char> > &board) {
    set<pair<int, int> > res;
    int n = (int)board.size();
    //vector <vector <bool> > visited(n, vector <bool>(n ,false));

    for (int i=0; i<n-1; i++) {
        for(int j=0; j<n-1; j++) {
            if(board[i][j] == 'X') {
                if(i>0 && board[i-1][j] == 'X' && board[i+1][j] == 'X' 
                    && (i<=1 || board[i-2][j] != 'X') && (i >= n-2 || board[i+2][j] != 'X')) {
                    res.insert(make_pair(i, j));
                } 
                if(j > 0 && board[i][j-1] == 'X' && board[i][j+1] == 'X'
                    && (j<=1 || board[i][j-2] != 'X') && (j >= n-2 || board[i][j+2] != 'X')) {
                    res.insert(make_pair(i, j));
                }
            }
        }
    }
    return res;
}

// BFS without check valid ship
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int res = 0, m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' && !visited[i][j]) {
                    ++res;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto t = q.front(); q.pop();
                        visited[t.first][t.second] = true;
                        for (auto dir : dirs) {
                            int x = t.first + dir[0], y = t.second + dir[1];
                            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || board[x][y] == '.') continue;
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        return res;
    }
};


// DFS with checking valid ship or not 
// Record the position of 'X', and using "or" to check wehther the x cordinate and y cordinate of every ponit are sema with the recording point
// x is equal, they are at same row, if y is equal they are at same col
class Solution2 {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return 0;
        int m = board.size(), n = board[0].size(), res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'X' && !visited[i][j]) {
                    int vertical = 0, horizontal = 0;
                    dfs(board, visited, vertical, horizontal, i, j);
                    if (vertical == i || horizontal == j) ++res;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int& vertical, int& horizontal, int i, int j) {
        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] == '.') return;
        vertical |= i; horizontal |= j;
        visited[i][j] = true;
        dfs(board, visited, vertical, horizontal, i - 1, j);
        dfs(board, visited, vertical, horizontal, i + 1, j);
        dfs(board, visited, vertical, horizontal, i, j - 1);
        dfs(board, visited, vertical, horizontal, i, j + 1);
    }
};
// set<pair<int, int> > checkboard(vector <vector <char> > &board, int x, int y) {
//     set<pair<int, int> > res;
//     int size = (int)board.size() - 1;
//     int dirs[4][4] = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
//     for(auto d:dirs) {
//         int m = x + d[0], n = y + d[1];
//         if(m < 0 || n < 0 || m > size || n > size) continue;
//         if(board[m][n] == 'X') {
//             if(board[x][y] == 'X') res.insert(make_pair(x, y));
//             else res.insert(make_pair(m, n));
//         }
//         // if(board[x][y] == 'X') {
//         //     if(board[m][n] == 'X') res.insert(make_pair(m, n));
//         //     else res.insert(make_pair(x, y));
//         // }
//     }
//     return res;
// }

// set<pair<int, int> > findplot(vector<vector<char> > &board, int n, int step) {
//     set<pair<int, int> > res;
//     for(int i=0; i<n; i++) {
//         for(int j=i%step; j<n; j += step) {
//             set<pair<int, int> > tem = checkboard(board, i, j);
//             if(!tem.empty()) {
//                 for(auto it : tem) {
//                     if(!res.count(it)) res.insert(it);
//                 }
//             }
//         }
//     }
//     return res;
// }
};

int main() {
    int n = 8;
    vector<vector<char> > board(n, vector<char>(n, 'E'));

    // board[0][3] = 'X';
    // board[0][1] = 'X';
    // board[0][2] = 'X';
    
 
    board[0][1] = 'X';
    board[0][2] = 'X';
    board[0][3] = 'X';
    board[0][4] = 'X';
    board[0][5] = 'X';
    board[0][6] = 'X';
    board[2][3] = 'X';
    board[3][3] = 'X';
    board[4][3] = 'X';
    board[5][4] = 'X';
    board[5][5] = 'X'; 
    board[5][6] = 'X';
    Battleboard ss;
    //set <pair <int, int> > res = ss.findplot(board, n, step);
    set <pair <int, int> > res = ss.getships(board);
    cout << "All the coordinate battleships are:" << endl;
    for(auto it : res) 
        cout <<"(" << it.first << ", " << it.second << ")\n";
    return 0;
    
    
}