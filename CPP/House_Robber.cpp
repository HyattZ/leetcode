#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_length = nums.size();
        vector<int> skip(nums_length + 1, 0);
        vector<int> take(nums_length + 1, 0);

        for (int i = 0 ; i < nums_length ; i++){
            take[i + 1] = skip[i] + nums[i];
            skip[i + 1] = max(skip[i], take[i]);
        }

        return max(skip[nums_length], take[nums_length]);

    }
};
