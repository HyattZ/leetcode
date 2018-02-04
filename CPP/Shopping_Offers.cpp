#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {

        /*这是搜索的写法，遍历有所的可能，找到最小的那个*/
        int needs_length = needs.size();
        int total_price = 0;
        for (int i = 0 ; i < needs_length; i++){
            total_price += (price[i] * needs[i]);
        }

        for (auto offer: special){
            bool is_useful = true;
            for (int i = 0 ; i < needs_length; i++){
                if (needs[i] < offer[i]){
                    is_useful = false;
                }
                needs[i] -= offer[i];
            }

            if (is_useful){
                total_price = min(total_price, shoppingOffers(price, special, needs) + offer.back());
            }

            //为了搜索的一致性，也就是说在第一层，要找所有可能的offer，从其中选择一个最小的
            for (int j = 0; j < needs_length; j++){
                needs[j] += offer[j];
            }
        }

        return total_price;
    }

};
