#include <iostream>
#include <vector>
using namespace std;

//180度旋转一个数字，看旋转之后的数字是否和原来相等， 比如 609 --> 60‍‍‍‍‌‌‌‍‌‍‍‌‍‍‍‌‍‍‍9  True,   711-->11L False
class Solution {
    bool equalAfterRotate(string num) {
        int l =0, r = num.size() -1;
        while(l <= r) {
            if(num[l] == num[r]) {
                if(num[l] != '1' && num[l] != '0' && num[l] != '8')
                    return false;
            } else {
               if ((num[l] != '6' || num[r] != '9') && (num[l] != '9' || num[r] != '6'))
                    return false;
            }
            l++;
            r--;
        }
        return true;
    }
    }
};