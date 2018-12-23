#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> r{""};
        if (digits.empty()){
            return {};
        }
        vector<string>dig{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> group;
            string ss = dig[digits[i]-'0'];
            for (int j = 0; j < ss.size(); ++j) {
                for(string s: r){
                    group.push_back(s+ss[j]);
                }
            }
            r = group;
        }
        return r;

    }

};
int main() {
    Solution *s = new Solution;
    s->letterCombinations("23");

    return 0;
}