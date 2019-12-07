#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses, 0);
        for(auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(in[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int tem = q.front();
            q.pop();
            for(auto i:graph[tem]) {
                in[i]--;
                if(in[i] == 0) q.push(i);
            }
        }
        for(int i=0; i<numCourses; i++) {
            if(in[i] != 0) return false;
        }
        return true;
    }
};