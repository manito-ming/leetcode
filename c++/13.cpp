#include <iostream>
#include <map>

using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        map<char ,int > map1={{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            int val = map1[s[i]];
            cout<<map1[s[i+1]]<<endl;   //如果在map里面找不到是0,这句话是为了检验if里面的map1,没有任何作用
            if (i == length -1 || map1[s[i+1]] <= map1[s[i]]){//第一个是判断是否是最后一个数字,第二个是判断右边的数字是否比左边的数字小
                res+=val;
            } else{
                res-=val;
            }
        }
        return res;
    }
};

class Solution1 {
public:
    int romanToInt(string s) {
        int res = 0;
        map<char ,int > map1={{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            int val = map1[s[i]];
            cout<<map1[s[i+1]]<<endl;   //如果在map里面找不到是0,这句话是为了检验if里面的map1,没有任何作用
            if (i == length -1 || map1[s[i]] <= map1[s[i-1]]){//第一个是判断是否是最后一个数字,第二个是判断右边的数字是否比左边的数字小
                res+=val;
            } else{
                res+=val-2*map1[s[i-1]];
            }
        }
        return res;
    }
};
int main() {

    string ss;
    cin >>ss;
    cout<<endl;
    Solution *s = new Solution;
    cout<<s->romanToInt(ss)<<endl;

    Solution1 *s1 = new Solution1;
    cout<<s1->romanToInt(ss)<<endl;
    return 0;
}