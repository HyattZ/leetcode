#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    //这是所谓 “记忆化搜索”算法
    int DP(int start, int end, vector<int> &nums, vector<vector<int> > &dp){
        if (dp[start][end] > 0){
            return dp[start][end];
        }

        for (int i = start; i <= end; i++){
            int tmp = DP(start, i - 1, nums, dp) + nums[start - 1]* nums[i]* nums[end + 1] +  DP(i + 1, end, nums, dp);
            if (tmp > dp[start][end]){
                dp[start][end] = tmp;
            }
        }
        return dp[start][end];
    }

    int maxCoins(vector<int>& nums) {
        int nums_length = nums.size();

        if (nums_length == 0){
            return 0;
        }

        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        vector<vector<int> > dp(nums_length + 2, vector<int>(nums_length + 2, 0));

        return DP(1, nums_length, nums, dp);
    }
};
