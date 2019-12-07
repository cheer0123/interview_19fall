#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath> 
using namespace std;


// Dataset1
// 恐龙名字， 恐龙腿长， 恐龙食性（食草，食肉，两者皆吃，这个是无关feature)

// Dataset2
// 恐龙名字， 恐龙某个feature(...

// Dataset2
// 恐龙名字， 恐龙某个feature(暂名d1), Stance(两只脚，四只脚等）

// 要求，选出stance是两只脚走路的恐龙，计算出他们的速度，并根据速度排序，然后从快到慢输出名字。.

// 速度是根据腿长以及d1来算出来的。

// 看上述要求，很明显先扫dataset2, 写一个class，然后放到map里。 最后处理第一个dataset， 算出speed,放到heap中。输出。


/*
dinosaurs question

You will be supplied with two data files in CSV format. The first file contains
statistics about various dinosaurs. The second file contains additional data.

Given the following formula,

speed = ((STRIDE_LENGTH / LEG_LENGTH) - 1) * SQRT(LEG_LENGTH * g)
Where g = 9.8 m/s^2 (gravitational constant)
(normal code)
Write a program to read in the data files from disk, it must then print the names
of only the bipedal dinosaurs from fastest to slowest. Do not print any other information.

$ cat dataset1.csv
NAME,LEG_LENGTH,DIET
Hadrosaurus,1.2,herbivore
Struthiomimus,0.92,omnivore
Velociraptor,1.0,carnivore
Triceratops,0.87,herbivore
Euoplocephalus,1.6,herbivore
Stegosaurus,1.40,herbivore
Tyrannosaurus Rex,2.5,carnivore

$ cat dataset2.csv
NAME,STRIDE_LENGTH,STANCE
Euoplocephalus,1.87,quadrupedal
Stegosaurus,1.90,quadrupedal
Tyrannosaurus Rex,5.76,bipedal
Hadrosaurus,1.4,bipedal
Deinonychus,1.21,bipedal
Struthiomimus,1.34,bipedal
Velociraptor,2.72,bipedal 
*/

class dinosaurs {
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

float speed(float leg_length, float stride_length) {
    return ((stride_length/ leg_length) -1) * sqrt(leg_length * 9.8);
}

vector<string> caluculate(vector<string> file1, vector<string> file2) {
    // <name, STRIDE_LENGTH> m2;
    unordered_map<string, float> m2;
    for(int i=0; i<file2.size(); i++) {
        vector<string> features2 = read_line(file2[i]);
        if(features2[2] == "bipedal") {
            m2[features2[0]] = stof(features2[1]);
        }
    }
    
    unordered_map <string, float> m;
    // <name, leg_LENGTH> m;
    for(int i=0; i<file1.size(); i++) {
        vector<string> features1 = read_line(file1[i]);
        if(m2.count(features1[0])) {
            //seepd(leg_length, strip_length)
            m[features1[0]] = speed(stof(features1[1]), m2[features1[0]]);
        }
    }
    
    
    priority_queue <pair<float, string> > q;
    for(auto it:m) {
        q.push(make_pair(it.second, it.first));
    }
    vector<string> res;
    while(!q.empty()) {
        auto t = q.top(); q.pop();
        res.push_back(t.second);
    }
    return res;
}
};

int main () {
    dinosaurs d;
    ifstream s1("file1.csv");
    ifstream s2("file2.csv");
    vector<string> file1 = d.parse_file(s1);
    vector<string> file2 = d.parse_file(s2);
    vector <string> res = d.caluculate(file1, file2);
    cout <<"The names of only the bipedal dinosaurs from fastest to slowest is:" <<endl;
    for (auto it : res) {
        cout << it << endl;
    }
    return 0;
}