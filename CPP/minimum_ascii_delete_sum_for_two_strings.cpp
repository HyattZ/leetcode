#include <string>

class Solution {
public:
    int minimumDeleteSum(std::string s1, std::string s2) {
        int s_length_1 = s1.size();
        int s_length_2 = s2.size();

        std::vector<std::vector<int> > dp(s_length_1 + 1, std::vector<int>(s_length_2 + 1, 0));

        for (int i = 1 ; i < s_length_1 + 1; i++){
            for (int j = 0 ; j < i ; j++){
                dp[i][0] += s1[j];
            }
        }

        for (int i = 1 ; i < s_length_2 + 1; i++){
            for (int j = 0 ; j < i ; j++){
                dp[0][i] += s2[j];
            }
        }

        for (int i = 1; i < s_length_1 + 1; i++){
            for (int j = 1; j < s_length_2 + 1; j++){
                if (s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    dp[i][j] = std::min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }

        /*
        for (int i = 0; i < s_length_1 + 1; i++){
            for (int j = 0; j < s_length_2 + 1; j++){
                std::cout << dp[i][j] << " ";
            }
            std::cout << std::endl;
        }
        */

        return dp[s_length_1][s_length_2];
    }
};
