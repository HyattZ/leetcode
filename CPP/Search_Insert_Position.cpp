#ifndef SEARCH_INSERT_POSITION_H_INCLUDED
#define SEARCH_INSERT_POSITION_H_INCLUDED

#include <vector>

#endif // SEARCH_INSERT_POSITION_H_INCLUDED

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int nums_size = nums.size();

        if (nums_size == 0){
            return 0;
        }

        int left = 0;
        int right = nums_size - 1;

        while(left < right){
            int mid = (left + right) / 2;
            if (target < nums[mid]){
                right = mid;
            }else if (target > nums[mid]){
                left = mid + 1;
            }else{
                return mid;
            }
        }
        if (nums[left] >= target){
            //这里的等于应对[1] ,1的这种输入
            return left;
        }else{
            return left + 1;
        }

    }
};
