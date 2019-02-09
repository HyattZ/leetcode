#ifndef STRING_WITHOUT_AAA_OR_BBB_H_INCLUDED
#define STRING_WITHOUT_AAA_OR_BBB_H_INCLUDED

#include <string>

#endif // STRING_WITHOUT_AAA_OR_BBB_H_INCLUDED

using namespace std;

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string result;
        strWithout3a3b(A, B, result);
        return result;
    }

    void strWithout3a3b(int A, int B, string& result){
        char prev = 'a';
        if (result.size() > 0){
            prev = result.at(result.size() - 1);
        }

        char xor_char = (char) (prev ^ 'a' ^ 'b');

        if (A == 0 && B == 0){
            return ;
        }

        if (A == 0){
            result.append("b");
            return strWithout3a3b(0, B - 1, result);
        }

        if (B == 0){
            result.append("a");
            return strWithout3a3b(A - 1, 0 , result);
        }

        if (A == B){
            result.append(1, xor_char).append(1, (char) (xor_char ^ 'a' ^ 'b'));
            return strWithout3a3b(A - 1, B - 1, result);
        }else if (A > B){
            result.append("aab");
            return strWithout3a3b(A - 2, B - 1, result);
        }else{
            result.append("bba");
            return strWithout3a3b(A - 1, B - 2, result);
        }

    }
};
