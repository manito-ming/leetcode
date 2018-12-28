#include <iostream>
#include<vector>
using namespace std;
/*这道题是 Catalan Number卡塔兰数的一个例子,开始我也没有头绪,
 * 在网上查完之后才知道,具体的解题思路:
 * 我们把n = 0 时赋为1，因为空树也算一种二叉搜索树，那么n = 1时的情况可以看做是其左子树个数乘以右子树的个数，左右字数都是空树，所以1乘1还是1。那么n = 2时，由于1和2都可以为跟，分别算出来，再把它们加起来即可。n = 2的情况可由下面式子算出：

dp[2] =  dp[0] * dp[1]　　　(1为根的情况)

　　　　+ dp[1] * dp[0]　　  (2为根的情况)

同理可写出 n = 3 的计算方法：

dp[3] =  dp[0] * dp[2]　　　(1为根的情况)

　　　　+ dp[1] * dp[1]　　  (2为根的情况)

 　　　  + dp[2] * dp[0]　　  (3为根的情况)

由此可以得出卡塔兰数列的递推式为：
vector[n] = vector[0]*vector[n-1]+vector[1]*vector[n-2]+...+vector[n]*vector[1];
 **/
class Solution {
public:
    int numTrees(int n) {
    vector<int> vector(n+1,0);
    vector [0]=1;
    vector[1]=1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <i; ++j) {
            vector[i] += vector[j]*vector[i-j-1];
        }
    }
        return vector[n];
    }
};
int main() {
    Solution *s = new Solution;
    int n=3;
    cout<<s->numTrees(n);
    return 0;
}