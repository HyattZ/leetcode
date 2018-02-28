#ifndef KTH_SMALLEST_ELEMENTIN_A_SORTED_MATRIX_H_INCLUDED
#define KTH_SMALLEST_ELEMENTIN_A_SORTED_MATRIX_H_INCLUDED

#include <vector>
#include <iostream>
#include <algorithm>

#endif // KTH_SMALLEST_ELEMENTIN_A_SORTED_MATRIX_H_INCLUDED

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int start = matrix[0][0];
        int end = matrix[n - 1][n - 1];
        int cnt = 0;

        while(start < end){
            cnt = 0;
            int mid = (start + end) / 2;
            for (int i = 0 ; i < n; i++){
                cnt += (upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin());
            }

            if (k > cnt){
                start = mid + 1;
            }else{
                //这一步有深意呀，当cnt = k时，得到的数字可能不是数组中的，这个时候，还继续缩小范围，知道start = end，可以保证数字在数组中
                end = mid;
            }
        }

        return start;

    }
};
