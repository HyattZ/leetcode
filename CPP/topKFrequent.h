#ifndef TOPKFREQUENT_H_INCLUDED
#define TOPKFREQUENT_H_INCLUDED

#include <vector>
#include <map>
#include <algorithm>

#endif // TOPKFREQUENT_H_INCLUDED

using namespace std;

int cmp(const pair<int, int>& x, const pair<int, int>& y){
    return x.second > y.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> num_map;
        vector<int> results;

        for (int num : nums){
            if (num_map.find(num) == num_map.end()){
                num_map.insert(pair<int, int>(num, 1));
            }else{
                num_map[num] = num_map[num] + 1;
            }
        }

        // sort(num_map.begin(), num_map.end(), cmp);
        vector<pair<int, int>> num_vec(num_map.begin(), num_map.end());
        sort(num_vec.begin(), num_vec.end(), cmp);

        for (int i = 0 ; i < k; i++){
            //cout << num_vec[i].first << endl;
            results.push_back(num_vec[i].first);
        }

        return results;
    }
};
