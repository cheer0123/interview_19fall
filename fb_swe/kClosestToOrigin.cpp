#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <queue>

using namespace std;
//Here we need a custom comparator to compare the closeness of points. 
//This solution is of O(nlogK) time. If we ignore the space of the output since that is inevitable,
// this solution is of O(1) space.
class Solution1 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin() + K, points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

// quick select
// This reduces the expected complexity from O(n log n) to O(n), with a worst case of O(n^2).
class Solution2 {
public:9
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int l = 0, r = points.size() - 1;
        while (true) {
            int p = partition(points, l, r);
            if (p == K - 1) {
                break;
            }
            if (p < K - 1) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
private:
    // bool further(vector<int>& p, vector<int>& q) {
    //     return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
    // }
    
    bool closer(vector<int>& p, vector<int>& q) {
        return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
    }
    int partition(vector<vector<int>>& points, int l, int r) {
        int pivot = r, i = l -1;
        for(int j=l; j <= r; j++) {
            if(closer(points[j], points[pivot])) {
                i++;
                swap(points[i], points[j]);
            }
        }
        swap(points[i + 1], points[r]);
        return i+1;
    }
    
    // int partition(vector<vector<int>>& points, int left, int right) {
    //     int pivot = left, l = left + 1, r = right;
    //     while (l <= r) {
    //         if (further(points[l], points[pivot]) && closer(points[r], points[pivot])) {
    //             swap(points[l++], points[r--]);
    //         }
    //         if (!further(points[l], points[pivot])) {
    //             l++;
    //         }
    //         if (!closer(points[r], points[pivot])) {
    //             r--;
    //         }
    //     }
    //     swap(points[pivot], points[r]);
    //     return r;
    // }
};

// min heap O(n + Klogn)
// pop() -> O(n)
class Solution3 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // put element into pq, O(n)
        priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());
        vector<vector<int>> ans;
        for (int i = 0; i < K; i++) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
private:
    struct compare {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
        }
    };
};

