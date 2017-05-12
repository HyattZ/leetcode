#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

class Solution {
public:
    Solution(){
        charSet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        long2Short.clear();
        short2Long.clear();
        srand(time(NULL));
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {

        if (long2Short.count(longUrl) != 0){
            return long2Short[longUrl];
        }

        string randStr;
        for (int i = 0 ; i < 6 ; i++){
            randStr.push_back(charSet[rand()%62]);
        }

        int pos = 0 ;
        while (short2Long.count(randStr)){
            randStr[pos] = charSet[rand()%62];
            pos = (pos+1) % 6;
        }

        long2Short[longUrl] = randStr;
        short2Long[randStr] = longUrl;

        return "http://tinyurl.com/"+randStr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {

        string randStr = shortUrl.substr(shortUrl.find_last_of('/')+1);

        return (short2Long.count(randStr) == 1)?short2Long[randStr]:shortUrl;
    }
private:
    map<string,string> short2Long,long2Short;
    string charSet;
};

int main(){
    Solution solution;
    //cout << solution.encode("https://leetcode.com/problems/design-tinyurl") << endl;
    cout << solution.decode(solution.encode("https://leetcode.com/problems/design-tinyurl")) << endl;
    return 0;
}
