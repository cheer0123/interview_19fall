#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> Movies_on_Flight(vector<int> &movieDurations, int d) {
    unordered_map<int, vector<int>> value2index;
    for(int i=0; i < movieDurations.size(); i++) {
        if(value2index.find(movieDurations[i]) == value2index.end()) {
            value2index[movieDurations[i]] = {i};
            }
            else value2index[movieDurations[i]].push_back(i);
    }

    sort(movieDurations.begin(), movieDurations.end());

    int left = 0, right = movieDurations.size()-1;
    int target = d-30;
    int maxDuration = 0;
    vector<int> res(2);
    vector<int> tem(2);

    while(left<right) {
        int cur = movieDurations[left] + movieDurations[right];
        if(cur == target) {
            tem[0] = movieDurations[left];
            tem[1] = movieDurations[right];
            break;
        }
        else if(cur < target) {
            if(cur > maxDuration) {
            tem[0] = movieDurations[left];
            tem[1] = movieDurations[right];
            maxDuration = cur;
            }
            left++;
        }
        else right--; 
    }

    if(tem[0] == tem[1]) {
        res[0] = value2index[tem[0]][0];
        res[1] = value2index[tem[1]][1];
    }
    else {
        res[0] = value2index[tem[0]][0];
        res[1] = value2index[tem[1]][0];
    }
    return res;
 }


void test(vector<pair<vector<int>, int>> inputs) {
    for(auto input: inputs) {
        vector<int> res = Movies_on_Flight(input.first, input.second);
        cout<<"["<<res[0]<<", "<<res[1]<<"]"<<endl;
    }
}

int main() {
    vector<pair<vector<int>, int>> inputs;
    inputs.push_back(make_pair(vector<int> {90, 85, 75, 60, 120, 150, 125}, 250));
    inputs.push_back(make_pair(vector<int> {90, 85, 75, 60, 120, 120, 150, 125}, 250));
    inputs.push_back(make_pair(vector<int> {0, 0, 0}, 30));
    inputs.push_back(make_pair(vector<int> {10, 50, 20, 40, 30, 30, 0, 60}, 90));
    test(inputs);
    
    return 0;
}