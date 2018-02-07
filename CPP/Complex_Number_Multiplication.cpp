#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int str2int(const string &str){
        stringstream stream(str);
        int int_num;
        stream >> int_num;
        return int_num;
    }

    string complexNumberMultiply(string a, string b) {
        int num_a_1 = str2int(a.substr(0, a.find('+') - 0));
        int num_b_1 = str2int(b.substr(0, b.find('+') - 0));
        int num_a_2 = str2int(a.substr(a.find('+') + 1, a.find('i') - a.find('+')));
        int num_b_2 = str2int(b.substr(b.find('+') + 1, b.find('i') - b.find('+')));
        stringstream stream;
        stream << num_a_1 * num_b_1 - num_a_2 * num_b_2<< "+" << num_a_1 * num_b_2 + num_a_2 * num_b_1<< "i";
        return stream.str();
    }
};
