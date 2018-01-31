#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int countSubstrings(std::string s) {
        int length = s.size();
        int result = 0;

        std::vector<std::vector<bool> > dp(length, std::vector<bool>(length, false));

        for (int i = length - 1; i >= 0 ; i--){
            for (int j = i ; j < length ; j++){
                if (s[i] == s[j]){
                    if (j - i <= 2){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }

                    if (dp[i][j]){
                        result++;
                    }
                }
            }
        }

        return result;
    }
};
