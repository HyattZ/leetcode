#ifndef FIND_SMALLEST_LETTER_GREATER_THAN_TARGET_H_INCLUDED
#define FIND_SMALLEST_LETTER_GREATER_THAN_TARGET_H_INCLUDED

#include <vector>

#endif // FIND_SMALLEST_LETTER_GREATER_THAN_TARGET_H_INCLUDED

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int letters_size = letters.size();

        int left = 0;
        int right = letters_size - 1;

        while(left < right){
            int mid = (right + left) / 2;
            if (target < letters[mid]){
                right = mid;
            }else if (target > letters[mid]){
                left = mid + 1;
            }else{
                int greater_pos = (mid + 1) % letters_size;

                while(letters[greater_pos] == target){
                    greater_pos = (greater_pos + 1) % letters_size;
                }

                return letters[greater_pos];
            }
        }

        int greater_pos;
        if (target > letters[left]){
            greater_pos = (left + 1) % letters_size;
        }else if(target < letters[left]){
            greater_pos = (left) % letters_size;
        }else{
            greater_pos = (left + 1) % letters_size;
        }

        while(letters[greater_pos] == target){
            greater_pos = (greater_pos + 1) % letters_size;
        }

        return letters[greater_pos];
    }
};
