#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int length = s.size();
        int result = 0;
        int start, end, max_length = -1;
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
                        if (j - i > max_length){
                            max_length = j - i;
                            start = i;
                            end = j;
                        }
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};
