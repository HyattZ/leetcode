#ifndef LONGEST_INCREASING_SUBSEQUENCE_H_INCLUDED
#define LONGEST_INCREASING_SUBSEQUENCE_H_INCLUDED

#include <vector>
#include <algorithm>

#endif // LONGEST_INCREASING_SUBSEQUENCE_H_INCLUDED

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nums_size = nums.size();

        if (nums_size == 0){
            return 0;
        }

        vector<int> dp(nums_size, 1);
        int result = 1;

        for (int i = 1; i < nums_size; i++){
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);

        }

        return result;
    }
};
