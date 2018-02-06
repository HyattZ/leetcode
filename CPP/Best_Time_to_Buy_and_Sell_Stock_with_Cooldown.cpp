#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prices_length = prices.size();

        if (prices_length == 0){
            return 0;
        }

        vector<int> buy(prices_length, 0);
        vector<int> cooldown(prices_length, 0);
        vector<int> sell(prices_length, 0);

        buy[0] = -prices[0];
        for (int i = 1; i < prices_length; i++){
            buy[i] = max(cooldown[i - 1] - prices[i], buy[i - 1]);
            cooldown[i] = sell[i - 1];
            sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
        }

        return sell[prices_length - 1];
    }
};
