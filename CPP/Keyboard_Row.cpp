#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row_1, row_2, row_3;
        string str_1, str_2, str_3;
        str_1 = "qwertyuiop";
        str_2 = "asdfghjkl";
        str_3 = "zxcvbnm";

        for (int i = 0 ; i < str_1.size(); i++){
            row_1.insert(str_1[i]);
        }

        for (int i = 0 ; i < str_2.size(); i++){
            row_2.insert(str_2[i]);
        }

        for (int i = 0 ; i < str_3.size(); i++){
            row_3.insert(str_3[i]);
        }

        vector<unordered_set<char> > rows;
        rows.push_back(row_1);
        rows.push_back(row_2);
        rows.push_back(row_3);

        vector<string> result;
        for (int i = 0; i < words.size(); i++){
            bool flags[] = {false, false, false};
            string word = words[i];
            for (int j = 0; j < word.size(); j++){
                if (word[j] <= 'Z'){
                    word[j] = word[j] + 32;
                }
            }

            for (int j = 0 ; j < word.size(); j++){
                for (int k = 0 ; k < 3; k++){
                    if (!flags[k] && rows[k].find(word[j]) != rows[k].end()){
                        flags[k] = true;
                    }
                }
            }

            int tmp_test = 0;
            for (int k = 0 ; k < 3; k++){
                if (flags[k]){
                    tmp_test++;
                }
            }

            if (tmp_test <= 1){
                result.push_back(words[i]);
            }
        }

        return result;
    }
};
