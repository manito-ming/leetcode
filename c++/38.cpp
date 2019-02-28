#include <iostream>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        if(n <= 0){
            return "";
        }
       while (--n){
           string cur="";

           for (int i = 0; i < s.size(); ++i) {
               int number = 1;
               while (i+1 < s.size() && s[i] == s[i+1]){
                   number++;//统计相同字符的个数
                   i++;//将指针向后移一位
               }
               cur += to_string(number)+s[i];
           }
           s = cur;
       }
        return s;
    }
};
int main() {
    Solution *s = new Solution;
    cout<<(*s).countAndSay(4)<<endl;
    return 0;
}