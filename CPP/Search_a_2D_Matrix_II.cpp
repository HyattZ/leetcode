#ifndef SEARCH_A_2D_MATRIX_II_H_INCLUDED
#define SEARCH_A_2D_MATRIX_II_H_INCLUDED

#include <vector>
#include <iostream>

#endif // SEARCH_A_2D_MATRIX_II_H_INCLUDED

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        if (m == 0){
            return false;
        }
        int n = matrix[0].size();
        if (n ==  0){
            return false;
        }

        int pos_m = 0;
        int pos_n = n - 1;

        while (pos_m < m && pos_n >= 0){
            if (target > matrix[pos_m][pos_n]){
                pos_m++;
            }else if (target < matrix[pos_m][pos_n]){
                pos_n--;
            }else{
                return true;
            }
        }

        return false;

    }
};
