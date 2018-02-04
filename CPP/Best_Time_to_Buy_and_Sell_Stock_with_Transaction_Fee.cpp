#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int prices_length = prices.size();
        vector<int> sold(prices_length, 0);
        vector<int> hold(prices_length, 0);

        // sold[i] ��ʾ����i��Ϊֹ��������Ʊ���ܵõ�����������
        // hold[i] ��ʾ����i��Ϊֹ��������Ʊ���ܵõ�����������
        hold[0] = -prices[0];

        for (int i = 1 ; i < prices_length; i++){
            sold[i] = max(hold[i - 1] + prices[i] - fee, sold[i - 1]);
            hold[i] = max(sold[i - 1] - prices[i], hold[i - 1]);
        }

        return sold.back();

    }
};
