#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int A_length = A.size();
        int B_length = B.size();

        //dp[i][j] ��ʾ��A[i - 1]��B[j - 1]��β����󹫹��Ӵ�����
        vector<vector<int> > dp(A_length + 1, vector<int>(B_length + 1, 0));

        int max_length = INT_MIN;
        for (int i = 1 ; i < A_length + 1; i++){
            for (int j = 1; j < B_length + 1; j++){
                if (A[i - 1] == B[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = 0;
                }
                max_length = max(max_length, dp[i][j]);
            }
        }

        /*
        for (int i = 0 ; i < A_length + 1; i++){
            for (int j = 0; j < B_length + 1; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */

        return max_length;
    }
};
