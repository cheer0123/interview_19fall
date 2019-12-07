// 从多个html文件中替换其中的email。我知道这个题其实最简单的是用正则表达式。如果非要c++程序实现的话，其实就是实现一个文件中字符串替换的函数。
// 此题的点在于导入文件到vector。寻找字符串，找到后替换，然后再写回文件。以下贴出本人写的可编译运行的代码。

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Solution{
public:
    string replace_str(string &s, string &nat, string &rep) {
        while (true) {
            int pos = s.find(nat);
            if (pos == (int) string::npos) break;
            s.replace(pos, (int) nat.size(), rep);
        }
        return s;
    }
};

int main (int argc, char ** argv) {
    if (argc != 4) {
        cout <<"Invalid!" << endl;
        exit(0);
    }
    ifstream s(argv[1]);
    if (!s) {
        cout << "Does not exit" << endl;
        exit(1);
    }
    string nat = argv[2];
    string rep = argv[3];
    Solution b;
    vector <string> in;
    string out;
    while (getline(s, out)) {
        out = b.replace_str(out, nat, rep);
        in.push_back(out);
    }
    ofstream r(argv[1]);
    for (int i = 0 ; i < (int)in.size(); ++i) {
        r <<  in[i] + '\n';
    }
    return 0;
}