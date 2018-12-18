#include <iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.empty() || needle.empty())
        {
            return  0;
        }
        int n =needle.size();
        for (int i = 0; i < haystack.size(); i++) {

            if (haystack.size()-i-1 >=n)
            {
                cout<<i<<" ~ "<<n<<" "<<haystack.substr(i,n)<<" ";//读取从第i个位置往后读n个字符
                if (needle == haystack.substr(i,n))
                {
                    return i;
                }
            } else{
                if (needle == haystack.substr(i,n))
                {
                    return i;
                }
                return -1;
            }

        }
        return -1;
    }
};
int main() {
    string  haystack = "hello", needle = "ll";
    Solution *s = new Solution;
    cout<<s->strStr(haystack,needle);
    return 0;
}