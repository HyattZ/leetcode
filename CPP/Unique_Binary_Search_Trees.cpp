#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n ; i++){
            int sum = 0;
            for (int j = i - 1 ; j >= 0; j--){
                sum += dp[j] * dp[i - j - 1];
            }
            dp[i] = sum;
        }

        return dp[n];
    }
};
