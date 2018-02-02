class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int result[] = {1, 9, 9*9, 9*9*8, 9*9*8*7, 9*9*8*7*6, 9*9*8*7*6*5, 9*9*8*7*6*5*4, 9*9*8*7*6*5*4*3, 9*9*8*7*6*5*4*3*2};
        if (n >= 10){
            int sum = 0;
            for (int i = 0 ; i <= 9 ; i++){
                sum += result[i];
            }
            return sum;
        }else{
            int sum = 0;
            for (int i = 0 ; i <= n ; i++){
                sum += result[i];
            }
            return sum;
        }
    }
};
