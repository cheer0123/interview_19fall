#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxScore(vector<vector<int> >& grid){
  if (grid.empty() || grid[0].empty()) return 0;
  for (int i = 1; i < grid[0].size(); i++){
    grid[0][i] = min(grid[0][i], grid[0][i-1]);
  }
  for (unsigned int i = 1; i < grid.size(); i++){
    grid[i][0] = min(grid[i][0], grid[i-1][0]);
  }

  for (int i = 1; i < grid.size(); i++){
    for (int j = 1; j < grid[0].size(); j++){
      grid[i][j] = max(min(grid[i-1][j], grid[i][j]),min(grid[i][j-1], grid[i][j]));
    }
  }
  return grid[grid.size()-1][grid[0].size()-1];
}


int main() {
    vector<vector<int>> grid1 {{5, 1}, {4, 5}};
    vector<vector<int> > grid2 {{5, 1, 7}, {4, 8, 5}};
    vector<vector<int> > grid3 {{1, 9, 9}, {9, 9, 9}, {9, 9, 9}};
    vector<vector<int> > grid4 {{10, 7, 3}, {12, 11, 9}, {1, 2, 8}};
    vector<vector<int> > grid5 {{20, 20, 3}, {20, 3, 20}, {3, 20, 20}};

    cout << "Max score should be 4: " << maxScore(grid1) << "\n";
    cout << "Max score should be 4: " << maxScore(grid2) << "\n";
    cout << "Max score should be 1: " << maxScore(grid3) << "\n";
    cout << "Max score should be 8: " << maxScore(grid4) << "\n";
    cout << "Max score should be 3: " << maxScore(grid5) << "\n";
}