#include<iostream>
#include<vector>

class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& A) {
        int length = A.size();
        int result = 0;
        std::vector<std::vector<bool> > dp(length, std::vector<bool>(length, false));

        for (int i = length - 1; i >= 0 ; i--){
            for (int j = i ; j < length ; j++){
                if (j - i + 1>= 3){
                    if (j - i + 1 == 3){
                        if (A[j] - A[j - 1] == A[j - 1] - A[j - 2]){
                            dp[i][j] = true;
                        }
                    }else{
                        dp[i][j] = dp[i][j-1] && (A[j] - A[j - 1] == A[j - 1] - A[j - 2]);
                    }

                    if(dp[i][j]){
                        result++;
                    }
                }
            }
        }

        return result;
    }
};
