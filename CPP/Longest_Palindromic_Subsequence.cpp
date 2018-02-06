#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int s_length = s.size();
        vector<vector<int> > dp(s_length, vector<int>(s_length, 0));
        for (int i = s_length - 1 ; i >= 0; i--){
            dp[i][i] = 1;
            for (int j = i + 1 ; j < s_length ; j++){
                if (s[j] == s[i]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][s_length - 1];
    }
};
