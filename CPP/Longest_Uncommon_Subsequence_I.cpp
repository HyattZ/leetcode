#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        int a_length = a.size();
        int b_length = b.size();

        if (a == b){
            return -1;
        }else{
            return max(a_length, b_length);
        }
    }
};
