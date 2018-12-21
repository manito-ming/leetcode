#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = 0;
        int index = 0;
        int k = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] ==' ')
            {


                if (s[i-1] != ' ')//如果之前一个不是空格,就将j保存,最后.看最后一个是' ',如果是的话,就应该返回index
                {
                    index = j;
                }

                j = 0;

            } else{
//                if ( index>= 0 || index==-1)//判断最后一个是不是空格
//                {
                j++;

            }

        }
        if (s[s.size()-1] == ' ')
        {
            return index;
        } else{
            return j;
        }


    }
};
class Solution1 {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (i != 0 && s[i - 1] == ' ') res = 1;
                else ++res;
            }
        }
        return res;
    }
};


int main() {
    string s ="hello world";
    string s2 ="hello";
    string s3="a ";
    string s4 ="b   na    ";

    Solution *s1 = new Solution;
    cout<<s1->lengthOfLastWord(s3);
    Solution1 *ss1 = new Solution1;
    cout<<ss1->lengthOfLastWord(s3);
    return 0;
}