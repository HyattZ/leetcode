#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int> >& pairs) {
        int length = pairs.size();

        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int > dp(length, 1);
        for (int i = 1 ; i < length; i++){
            for (int j = i - 1 ; j >= 0 ; j--){
                if (pairs[j][1] < pairs[i][0]){
                    dp[i] = dp[j] + 1;
                    break;
                }
            }
            dp[i] = max(dp[i-1], dp[i]);
        }

        return dp[length - 1];
    }
};
