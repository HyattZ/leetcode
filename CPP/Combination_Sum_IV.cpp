#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /*
        // ֱ�����Ļ����ᳬʱ
        if (target == 0){
            return 1;
        }else if (target < 0){
            return 0;
        }

        int nums_length = nums.size();
        int sum = 0 ;

        for (int i = 0 ; i < nums_length; i++){
            sum += combinationSum4(nums, target - nums[i]);
        }

        return sum;
        */

        //�����������target���ܴܺ󣬴��˻ᵼ���ڴ汬��
        int result = 0;
        vector<unordered_map<int, int> > dp(target + 1);
        dp[0][0] = 1;
        for (int i = 1 ; i < target + 1 ; i++){
            for (auto prev: dp[i - 1]){
                for (int j = 0 ; j < nums.size(); j++){
                    if (prev.first + nums[j] == target){
                        result += prev.second;
                    }else if (prev.first + nums[j] < target){
                        dp[i][prev.first + nums[j]] += prev.second;
                    }
                }
            }
        }

        return result;

    }
};
