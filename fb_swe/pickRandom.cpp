#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>

using namespace std;

class Solution{
private:
    unordered_map<int, string> m;
public:
    vector<string> parse_file(ifstream &s) {
        vector<string> res;
        string out;
        while(getline(s, out)) {
            res.push_back(out);
            out.clear();
        }
        return res;
    }
    // input string "SanF:900 /n" "NY:100/n";
    unordered_map<string, int> readline(string s) {
        string out;
        for(int i=0; i<s.size(); i++) {
            while(isalpha(s[i])) {
                out += s[i];
            } 
            string city = out;
            out.clear();
            while(isdigit(s[i])) {
                out += s[i];
            }
            int people = stoi(out);
            m[people] = city;
        }
    }

    string pickCity() {
        vector<int> num;
        for(auto p:m) {
            num.push_back(p.first);
        }
        vector<int> sum = num;
        for(int i=1; i<num.size(); i++) {
            sum[i] = sum[i-1] + num[i];
        }
        int x = rand()%sum.back();
         // find the first num bigger than x
        int picked = upper_bound(sum.begin(), sum.end(), x) - sum.begin();
        return m[picked];
    }
};

int main() {
    
}
