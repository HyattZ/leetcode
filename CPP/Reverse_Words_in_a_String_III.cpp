#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<char> tmp_stack;
        stringstream ss;
        for (int i = 0 ; i < s.size(); i++){
            if (s[i] == ' '){
                while(!tmp_stack.empty()){
                    ss << tmp_stack.top();
                    tmp_stack.pop();
                }
                ss << ' ';
            }else{
                tmp_stack.push(s[i]);
            }
        }
        while(!tmp_stack.empty()){
            ss << tmp_stack.top();
            tmp_stack.pop();
        }

        return ss.str();
    }
};
