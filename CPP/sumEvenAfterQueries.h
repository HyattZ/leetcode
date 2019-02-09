#ifndef SUMEVENAFTERQUERIES_H_INCLUDED
#define SUMEVENAFTERQUERIES_H_INCLUDED

#include <vector>

#endif // SUMEVENAFTERQUERIES_H_INCLUDED

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> results;
        for (auto query : queries){
            A[query[1]] += query[0];
            int sum = 0;
            for (int num : A){
                if (num % 2 == 0){
                    sum += num;
                }
            }
            results.push_back(sum);
        }
        return results;
    }
};
