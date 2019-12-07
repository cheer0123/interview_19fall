#include <iostream>
#include <string.h>
#include <vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        vector<string> res;
        for(string cpdomain :  cpdomains) {
            int idx = cpdomain.find(' ');
            int cnt = stoi(cpdomain.substr(0, idx));
            string cmp = cpdomain.substr(idx + 1);
            for(int i=0; i<cmp.size(); i++) {
                if(cmp[i] == '.') {
                    m[cmp.substr(i+1)] += cnt;
                }
            }
            m[cmp] += cnt;
        }
        for(auto d:m) {
            res.push_back(to_string(d.second) + " " + d.first);
        }
        return res;
    }
};