#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        /*
        // Kadane's algorithm算法变种
        int nums_length = nums.size();

        int sum = 0 ;
        int max_sum = INT_MIN;

        for (int i = 0 ; i < nums_length ; i++){
            sum = max(sum + nums[i], nums[i]);
            max_sum = max(sum, max_sum);
        }

        return max_sum;
        */

        /*
        // Kadane's algorithm算法
        int max_ending_here = 0;
        int max_so_far = Integer.MIN_VALUE;

        for(int i = 0; i < nums.length; i++)
        {
            if(max_ending_here < 0)
                 max_ending_here = 0;
            max_ending_here += nums[i];
            max_so_far = Math.max(max_so_far, max_ending_here);
        }
        return max_so_far;
        */

        //分治算法
        int nums_length = nums.size();
        if (nums_length == 0){
            return 0;
        }

        return Max_SubArray_Sum(nums, 0, nums_length - 1);
    }

    int Max_SubArray_Sum(vector<int> &nums, int start, int end){
        if (start == end){
            return nums[start];
        }

        int middle = (start + end) / 2;
        int left_mss = Max_SubArray_Sum(nums, start, middle);
        int right_mss = Max_SubArray_Sum(nums, middle + 1, end);

        int left_sum = INT_MIN;
        int right_sum = INT_MIN;
        int sum = 0;

        for (int i = middle + 1; i <= end ; i++){
            sum += nums[i];
            right_sum = max(right_sum, sum);
        }

        sum = 0;
        for (int i = middle; i >= start; i--){
            sum += nums[i];
            left_sum = max(left_sum, sum);
        }

        int res = max(left_mss, right_mss);
        return max(res, left_sum + right_sum);
    }
};
