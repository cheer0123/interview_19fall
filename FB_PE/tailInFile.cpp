#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

class showtail {
public:
    void tail(ifstream &tmp, int count) {
        stack <string> res;
        string out;
        while (getline(tmp, out)) {
            res.push(out);
        }
        while (!res.empty() && count > 0) {
            string t = res.top();
            res.pop();
            cout << t << '\n';
            count--;
        }
    }
};

int main(int argc, char **argv) {
        if(argc != 3){
        cout <<"Usage:Please enter the value like ./tail -n file" <<endl;
        exit(0);
    }
    string n1 = argv[1];
    if (n1[0] != '-' || n1[1] < '0' || n1[1] > '9') {
            cout <<"Invalided line number, Please enter a valid number" << endl;
            exit(1);
    }
    string n2 = argv[2];
    ifstream ss(argv[2]);
    if (!ss) {
        cout << "Could not open a file, the target file does not exist" <<endl;
        exit(2);
    }
    int n = stoi(n1.substr(1));
    showtail m;
    m.tail(ss, n);
    return 0;
}
