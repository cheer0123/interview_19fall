#include <iostream>
#include <vector>

using namespace std; 
  
void printMatrixDiagonallyDown(vector<vector<int> > matrix,  int n) { 
    // printing elements above and on  
    // second diagonal 
    for (int k = 0; k < n; k++) { 
        // traversing downwards starting 
        // from first row 
        int row = 0, col = k; 
        while (col >= 0) { 
            cout << matrix[row][col] << " "; 
            row++, col--; 
        } 
    } 
  
    // printing elements below second 
    // diagonal 
    for (int j = 1; j < n; j++) { 
        // traversing downwards starting  
        // from last column 
        int col = n - 1, row = j; 
        while (row < n) { 
            cout << matrix[row][col] << " "; 
            row++, col--; 
        } 
    } 
} 
  
int main() { 
    vector<vector<int> > matrix{ { 1, 2, 3 }, 
                                 { 4, 5, 6 }, 
                                 { 7, 8, 9 } }; 
    int n = 3; 
    printMatrixDiagonallyDown(matrix, n); 
    return 0; 
} 