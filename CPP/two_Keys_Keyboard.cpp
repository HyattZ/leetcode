#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        //思路：找出n的因子，所有的因子可以当做模块的个数，再计算出模块
        //的长度n = n / i,调用递归，加上模块的个数i来更新结果res即可
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n ; i++){
            //当数字为素数的时候，其值为其自身。并且对于一个数来说其最大的值也是自身。
            dp[i] = i;
            for (int j = i - 1; j > 1 ; j--){
                if (i % j == 0){
                    dp[i] = min(dp[i], dp[j] + i / j);
                }
            }
        }

        return dp[n];
    }
};
