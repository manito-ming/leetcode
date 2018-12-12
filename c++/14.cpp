#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0)
        {
            return "";
        }
        for (int i = 0; i <strs[0].size(); i++) {
            for (int j = 0; j < strs.size(); j++) {
                cout<<strs[j][i]<<"\t"<<endl;  //c语言如果访问超过数组里面的时候里面会是空值,不报数组越界异常,所以不需要我注释掉的判断

//                    if (strs[j].size()<=strs[0].length())//这个是检查后面的字符串不能比第一个的长,如果后面的小的话,应该取得是小字符串的值
//                    {

                        if (strs[j][i] !=strs[0][i] )//这个是检查两个字符串是否相等,不相等的话就返回
                        {
                            return strs[0].substr(0,i);//从第0个往后读取i个字符
                        }
//                    } else{
////                        if (strs[j][j] !=strs[0][j] )//这个是检查两个字符串是否相等,不相等的话就返回
////                        {
////                        if (strs[j])
//                            return strs[0].substr(0,j);
////                        }
//                    }

            }
            cout<<endl;
        }
        return strs[0];
    }
};

class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        {
            return "";
        }
        for(int i=0;i<strs[0].size();++i){
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=strs[0][i])
                {
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    vector<string> strs={"ababasd","aba","aba","aba"};
    vector<string> strs1={"flower","flow","flight","fldf","flsdfg","flsd","flaw"};
    vector<string> strs2={"abab","a"};
    vector<string> strs3={"a","b"};
    vector<string> strs4={"a","ac"};
    vector<string> strs5={"dog","racecar","car"};


    Solution *s = new Solution;
    cout<<s->longestCommonPrefix(strs);

    Solution1 *s1 = new Solution1;
    cout<<s1->longestCommonPrefix(strs3);
    return 0;
}