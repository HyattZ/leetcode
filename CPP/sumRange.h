#ifndef NUMARRAY_H_INCLUDED
#define NUMARRAY_H_INCLUDED

#include <vector>

#endif // NUMARRAY_H_INCLUDED

using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        this->nums = nums;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i ; k <= j ; k++){
            sum += this.nums[k];
        }
        return sum;
    }
private:
    vector<int> nums;
};
