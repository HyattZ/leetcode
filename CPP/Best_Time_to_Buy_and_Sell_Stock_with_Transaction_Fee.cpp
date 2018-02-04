#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int prices_length = prices.size();
        vector<int> sold(prices_length, 0);
        vector<int> hold(prices_length, 0);

        // sold[i] 表示到第i步为止，卖出股票所能得到的最大的利润
        // hold[i] 表示到第i步为止，保留股票所能得到的最大的利润
        hold[0] = -prices[0];

        for (int i = 1 ; i < prices_length; i++){
            sold[i] = max(hold[i - 1] + prices[i] - fee, sold[i - 1]);
            hold[i] = max(sold[i - 1] - prices[i], hold[i - 1]);
        }

        return sold.back();

    }
};
