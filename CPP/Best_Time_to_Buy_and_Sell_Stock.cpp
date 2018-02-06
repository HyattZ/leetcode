#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prices_length = prices.size();

        int min_num = 0xFFFFFFF;
        int max_profit = 0;

        for (int i = 0 ; i < prices_length; i++){
            if (min_num > prices[i]){
                min_num = prices[i];
            }

            if (prices[i] - min_num > max_profit){
                max_profit = prices[i] - min_num;
            }
        }

        return max_profit;
    }
};
