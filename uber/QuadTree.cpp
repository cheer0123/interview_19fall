#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    bool val;
    bool isleaf;
    Node* topLeft;
    Node* bottomLeft;
    Node* topRight;
    Node* bottomRight;
    
    Node() {}
    Node(bool _val,bool _isleaf,  Node* _topLeft, Node* _bottomLeft, Node* _topRight, Node* _bottomRight) {
        val = _val;
        isleaf = _isleaf;
        topLeft = _topLeft;
        bottomLeft = _bottomLeft;
        topRight = _topRight;
        bottomRight = _bottomRight;
    }
};

// To do this recusively, we have to split the grid into 4 smaller sub-grids until the sub-grid's length is 1. 

// We merge the sub-grids if all four sub-grids are leaf nodes and have same value.
class Solution{
    Node* construct(vector<vector<int> >& grid) {
        return helper(grid, 0, 0, grid.size());
    }
    // DFS (start point(x, y), 边长 len)
    Node* helper(vector<vector<int> >& grid, int x, int y, int len) {
        if(len <= 0) return NULL;
        for(int i=x; i<len+x; i++) {
            for(int j=y; j<j+len; j++) {
                if(grid[i][j] != grid[x][y]) {
                    return new Node(false, false,
                                    helper(grid, x, y, len/2), 
                                    helper(grid, x, y+len/2, len/2), 
                                    helper(grid, x+len/2, y, len/2), 
                                    helper(grid, x+len/2, y+len/2, len/2) );
                }
            }
        }
        return new Node(grid[x][y] == 1, true, NULL, NULL, NULL, NULL);
    }
};

int main() {
    Solution s;
    vector<vector<bool> > gird(8, vector<bool>(10));
    
    
}