#ifndef FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_H_INCLUDED
#define FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_H_INCLUDED

#include<vector>

#endif // FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_H_INCLUDED

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int nums_size = nums.size();
        if (nums[0] <= nums[nums_size - 1]){
            return nums[0];
        }

        int left = 0, right = nums_size - 1;
        while(left != right - 1){
            int mid = (right + left) / 2;
            if (nums[mid] > nums[left]){
                left = mid;
            }else{
                right = mid;
            }
        }

        return nums[right];
    }
};
