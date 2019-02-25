#include <iostream>
#include <vector>

using namespace std;
//这是我开始的最笨的办法
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> y(numRows,vector<int>());
        vector<int> v = {1};
        y[0]=v;
        if (numRows ==1){
            return y;
        }
        vector<int> v1={1,1};
        y[1]=v1;
        if (numRows ==2){
            return y;
        }
        for (int i = 2; i < numRows; ++i) {
            vector<int> v2(i+1);
            v2[0]=1,v2[i]=1;
            for (int j = 1; j < i; ++j) {
                v2[j] = y[i-1][j-1]+y[i-1][j];
            }
            y[i]=v2;
        }
        return y;
    }
};
//解法二，使用了c++的库函数
class Solution1 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        for (int i = 0; i < numRows; ++i) {
            res[i].resize(i + 1, 1);//使用ｃ++的函数，创建了i+1大小的数组，初始化为１
            for (int j = 1; j < i; ++j) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};
int main() {
    Solution *s=new Solution;
    Solution1 *s1=new Solution1;

    int numRows = 5;
    vector<vector<int>> y= (*s1).generate(numRows);
    for (int i = 0; i < numRows; ++i) {
        cout<<"[";
        for (int j = 0; j < y[i].size(); ++j) {
            cout<<y[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}