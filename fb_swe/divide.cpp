#include <iostream> 
#include <vector> 

using namespace std;

//check boundary of input (INT_MIN, INT_MAX)?
// check sign, >=0 ? <= 0
class Soultion{
public:
    string divide(int dividend, int divisor) {
        string res;
        if(dividend == INT_MIN && divisor == -1) return "INT_MAX";
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        if(sign == '-') res += "-";
        
        while(dvd >= dvs) {
            long m = 1, tem = dvs;
            while(tem << 1 <= dvd) {
                tem <<= 1;
                m <<= 1;
            }
            dvd -= tem;
            ans += m;
        }
        res += to_string(ans);
        res += " rem ";
        res += to_string(dvd);
        return res;
    }
};

int main() {
    Soultion s;
    string out = s.divide(10, 3);
    cout<<out<<endl;
    return 0;
}