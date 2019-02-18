#ifndef SCOREOFPARENTHESES_H_INCLUDED
#define SCOREOFPARENTHESES_H_INCLUDED

#include <string>
#include <stack>

#endif // SCOREOFPARENTHESES_H_INCLUDED

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        char lastChar = ' ';
        int result = 0;
        stack<char> ch_stack;

        for (char ch : S){
            if (ch == '('){
                ch_stack.push('(');
            }else if (ch == ')'){
                if (lastChar == '('){
                    int base = 1;
                    for (int i = 1; i < ch_stack.size(); i++){
                        base *= 2;
                    }
                    result += base;
                }
                ch_stack.pop();
            }

            lastChar = ch;
        }
        return result;
    }
};
