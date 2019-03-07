#include <iostream>
using namespace std;

//解法一，递归重复计算太多
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n ==2){
            return 2;
        }
        return climbStairs(n-1)+climbStairs(n-2);
    }
};
//解法二　
class Solution1 {
public:
    int climbStairs(int n) {
        if(n == 0){
            return 0;
        }
        if(n==1 || n ==2){
            return n;
        }else{
            int res= 0;
            int i =1,j =2;
            int k =3;
            while(k<=n){
                res = i+j;
                i= j;
                j =res;
                k++;
            }
            return res;
        }


    }
};
int main() {
    Solution *s =new Solution;
    cout<<(*s).climbStairs(45);
    return 0;
}