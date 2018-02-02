#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // 递归方法不够有效，可以用动态规划方法，后续处理
    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums, 0 ,0 ,1);
    }

    bool canWin(vector<int>& nums, int sum_1, int sum_2, int palyer){
        if (nums.empty()){
            return sum_1 >= sum_2;
        }

        if (nums.size() == 1){
            if (palyer == 1){
                return sum_1 + nums[0] >= sum_2;
            }else{
                return sum_2 + nums[0] > sum_1;
            }
        }

        vector<int> v_start(nums.begin() + 1, nums.end());
        vector<int> v_end(nums.begin(), nums.end() - 1);

        if (palyer == 1){
            return !canWin(v_start, sum_1 + nums[0], sum_2, 2) || !canWin(v_end, sum_1 + nums.back(), sum_2, 2);
        }else{
            return !canWin(v_start, sum_1, sum_2 + nums[0], 1) || !canWin(v_end, sum_1, sum_2 + nums.back(), 1);
        }
    }
};
