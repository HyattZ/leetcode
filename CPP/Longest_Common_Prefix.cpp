#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int prefix_count = 0;
        std::string result;
        if (strs.size() == 0){
            return result;
        }

        int min_length = 0xFFFFFFF;
        for (int i = 0 ; i < strs.size(); i++){
            if (min_length > strs[i].size()){
                min_length = strs[i].size();
            }
        }

        while(prefix_count < min_length){
            bool is_break = false;
            char target_char = strs[0][prefix_count];
            for (int i = 0 ; i < strs.size(); i++){

                if (strs[i][prefix_count] != target_char){
                    is_break = true;
                    break;
                }
            }
            if (is_break){
                break;
            }
            result.append(1, target_char);
            prefix_count++;
        }

        return result;
    }
};
