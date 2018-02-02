#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        //˼·���ҳ�n�����ӣ����е����ӿ��Ե���ģ��ĸ������ټ����ģ��
        //�ĳ���n = n / i,���õݹ飬����ģ��ĸ���i�����½��res����
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n ; i++){
            //������Ϊ������ʱ����ֵΪ���������Ҷ���һ������˵������ֵҲ������
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
