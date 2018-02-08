#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // 讲道理，我还是不太明白这个dp递推方程
        // skip表示到第i个位置，如果选择跳过操作，所能获取到的最大的Earn的值
        // take表示到第i个位置，如果选择拿操作，所能获取到的最大的Earn的值
        vector<int> cnt(10001, 0);
        int nums_length = nums.size();

        for (int i = 0 ; i < nums_length; i++){
            cnt[nums[i]] += nums[i];
        }

        vector<int> take(10001, 0);
        vector<int> skip(10001, 0);

        for (int i = 1 ; i < 10001; i++){
            take[i] = skip[i - 1] + cnt[i];
            skip[i] = max(skip[i - 1], take[i - 1]);
        }

        return max(skip[10000], take[10000]);
    }
};
