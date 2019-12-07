#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
#include <sstream>
#include <stdio.h>
#include <fstream>

using namespace std;

class Solution {
    struct cmp{
        bool operator() (pair<string, int> a, pair<string, int> b) {
            return (a.second < b.second) || (a.second == b.second && a.first > b.first);
        }
    };
public:

//use fseek(file pointer, offset(number of byte move from ) ) place the file pointer at the beginning or given position 
// int fseek(FILE *stream, long int offset, int whence)
// SEEK_SET	文件的开头  SEEK_CUR 文件指针的当前位置 SEEK_END 文件的末尾
void testByChar() {
    fstream testByCharFile;
    char c;
    testByCharFile.open("inFile.txt",ios::in);
    // fseek(testByCharFile, 100, SEEK_SET);
    while(!testByCharFile.eof()) {
        testByCharFile>>c;
        cout<<c;
    }
    testByCharFile.close();
}

    vector<string> parse_file(ifstream &s) {
        vector<string> res;
        string out;
        while(getline(s, out)) {
            res.push_back(out);
            out.clear();
        }
        return res;
    }

// isalpha() , isdigit(), int islower()


    vector<string> parse_file(ifstream &s) {
        vector<string> res;
        string out;
        while(getline(s, out)) {
            res.push_back(out);
            out.clear();
        }
        return res;
    }
    vector<string> read_line(string s) { 
        vector<string> m;
        s.push_back(',');
        string t;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ',') {
                m.push_back(t);
                t.clear();
            } else t += s[i];
        }
        return m;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string i:words) {
            m[i]++;
        }
        // min heap
        priority_queue<pair<string, int>, vector<pair<string, int> >, cmp> pq;
        for (auto i:m) {
            pq.push(i);
        }
        vector<string> res;
        for (int i=0; i <k; i++) {
            string tem = pq.top().first;
            res.push_back(tem);
            pq.pop();
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> words;
    words.push_back("i");
    words.push_back("love");
    words.push_back("leet");
    words.push_back("code");
    words.push_back("i");
    words.push_back("love");
    words.push_back("code");
    vector<string> res = s.topKFrequent(words, 3);
    for(string word:res) cout<<word<<endl;
    return 0;
}