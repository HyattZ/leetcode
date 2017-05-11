#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int> >& wall) {
        int heightOfWall = wall.size();
        map<int,int> hash;
        int maxCount = 0;
        for (int  i = 0 ; i < heightOfWall ; i++){
            vector<int> tmp = wall[i];
            int sum = 0;
            for (int j = 0 ; j < tmp.size()-1 ; j++){
                sum += tmp[j];
                ++hash[sum];
            }
        }

        for (int i = 0 ; i < hash.size() ; i++){
            maxCount = max(hash[i],maxCount);
        }

        return heightOfWall - maxCount;
    }
};

int main(){
    Solution solution ;
    vector<vector<int> > input;

    vector<int> rowInput1,rowInput2,rowInput3,rowInput4,rowInput5,rowInput6;

    rowInput1.push_back(1);
    rowInput1.push_back(2);
    rowInput1.push_back(2);
    rowInput1.push_back(1);

    rowInput2.push_back(3);
    rowInput2.push_back(1);
    rowInput2.push_back(2);

    rowInput3.push_back(1);
    rowInput3.push_back(3);
    rowInput3.push_back(2);

    rowInput4.push_back(2);
    rowInput4.push_back(4);

    rowInput5.push_back(3);
    rowInput5.push_back(1);
    rowInput5.push_back(2);

    rowInput6.push_back(1);
    rowInput6.push_back(3);
    rowInput6.push_back(1);
    rowInput6.push_back(1);

    input.push_back(rowInput1);
    input.push_back(rowInput2);
    input.push_back(rowInput3);
    input.push_back(rowInput4);
    input.push_back(rowInput5);
    input.push_back(rowInput6);

    cout << solution.leastBricks(input) << endl;
    return 0;
}
