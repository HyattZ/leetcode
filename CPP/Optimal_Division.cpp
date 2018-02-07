#include<vector>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {

        //纯数学做法，在第一个数后面加括号时能得到最大的数
        // a / b / c /.../z
        // a / (b/ c /.../ z) = a * c * ... * z / b
        stringstream ss;
        if (nums.size() == 1){
            ss << nums[0];
            return ss.str();
        }else if (nums.size() == 2){
            ss << nums[0] << "/" << nums[1];
            return ss.str();
        }

        ss << nums[0] << "/(";
        for (int i = 1 ; i < nums.size() - 1; i++){
            ss << nums[i] << "/";
        }
        ss << nums[nums.size() - 1] << ")";

        return ss.str();
    }
};
