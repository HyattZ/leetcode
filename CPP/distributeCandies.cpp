#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int,bool> tmpMap ;
        for (int i = 0 ; i < candies.size() ; i++){
            tmpMap[candies[i]] = true;
        }

        if (tmpMap.size() > candies.size()/2){
            return candies.size()/2;
        }else{
            return tmpMap.size();
        }
    }
};

int main(){
    Solution solution;
    vector<int> input ;

    input.push_back(1);
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);

    cout << solution.distributeCandies(input) << endl;
}
