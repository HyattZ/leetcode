#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, bool> count_map;
        int result = 0;
        for (int i = 0 ; i < J.size(); i++){
            count_map[J[i]] = true;
        }

        for (int j = 0 ; j < S.size(); j++){
            if (count_map.find(S[j]) != count_map.end()){
                result++;
            }
        }

        return result;
    }
};
