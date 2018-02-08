#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // �������һ��ǲ�̫�������dp���Ʒ���
        // skip��ʾ����i��λ�ã����ѡ���������������ܻ�ȡ��������Earn��ֵ
        // take��ʾ����i��λ�ã����ѡ���ò��������ܻ�ȡ��������Earn��ֵ
        vector<int> cnt(10001, 0);
        int nums_length = nums.size();

        for (int i = 0 ; i < nums_length; i++){
            cnt[nums[i]] += nums[i];
        }

        vector<int> take(10001, 0);
        vector<int> skip(10001, 0);

        for (int i = 1 ; i < 10001; i++){
            take[i] = skip[i - 1] + cnt[i];
            skip[i] = max(skip[i - 1], take[i - 1]);
        }

        return max(skip[10000], take[10000]);
    }
};
