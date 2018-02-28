#ifndef FIND_THE_DUPLICATE_NUMBER_H_INCLUDED
#define FIND_THE_DUPLICATE_NUMBER_H_INCLUDED



#endif // FIND_THE_DUPLICATE_NUMBER_H_INCLUDED

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        int nums_size = nums.size();

        int standfard_sum = (1 + nums_size - 1) * (nums_size - 1) / 2;

        int sum = 0 ;
        for (int i = 0 ; i < nums_size; i++){
            sum += nums[i];
        }

        return sum - standfard_sum;
        */

        int nums_size = nums.size();

        int start = 1;
        int end = nums_size - 1;

        while(start < end){
            int mid = (start + end) / 2;
            int range = (mid - start) + 1;

            int cnt = 0 ;
            for (int i = 0 ; i < nums_size; i++){
                //这里求的是在范围内的数据
                if (nums[i] <= mid && nums[i] >= start){
                    cnt++;
                }
            }

            if (cnt <= range){
                start = mid + 1;
            }else{
                end = mid;
            }
        }

        return start;
    }
};
