#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        /*
        // �ݹ�������ʱ�����Կ���ʹ��dp�㷨
        int nums_length = nums.size();
        if (nums_length == 0){
            if (S == 0){
                return 1;
            }else{
                return 0;
            }
        }else{
            vector<int> nums_left = vector<int>(nums.begin() + 1, nums.end());
            return findTargetSumWays(nums_left, S + nums[0]) + findTargetSumWays(nums_left, S - nums[0]);
        }
        */

        // dp[i][j] ��ʾ��ǰi�������Һ�Ϊj���������������ʵ�����Ƕ��������������������ģ��
        int nums_length = nums.size();
        vector<unordered_map<int, int> > dp(nums_length + 1);
        dp[0][0] = 1;
        for (int i = 1 ; i < nums_length + 1; i++){
            unordered_map<int, int> next_cnt;
            for(auto &cnt_map: dp[i - 1]){
                int sum = cnt_map.first;
                int sum_count = cnt_map.second;

                next_cnt[sum + nums[i - 1]] += sum_count;
                next_cnt[sum - nums[i - 1]] += sum_count;
            }
            dp[i] = next_cnt;
        }

        return dp[nums_length][S];
    }
};
