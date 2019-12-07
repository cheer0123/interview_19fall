// Given an square matrix, turn it by 90 degrees in anti-clockwise direction
//  without using any extra space.
// Input
//  1  2  3
//  4  5  6
//  7  8  9

// Output:
//  3  6  9 
//  2  5  8 
//  1  4  7 

#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // change the element at dialog
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
//  1  2  3          1  4  7
//  4  5  6    ->    2  5  8
//  7  8  9          3  6  9

// reverse 
        for(int i=0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        return;
    }
};


