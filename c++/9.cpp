#include <iostream>
using namespace std;
//解法一
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        int div=1;
        while(x/div>=10)
        {
            div*=10;
        }
        while(x>0){
            int left = x/div;
            int right = x%10;
            if (left != right)
            {
                return false;
            }
            x=x%div;//这个取余,会把前面的数字去掉,只剩下后面的数字了,例如112%100=12
            x/=10;  //这个可以把最后几位数字去掉,例如 112/10=11,
            div/=100;
        }
        return true;
    }
};

//解法二
class Solution1{
public:
    bool isPalindrome(int x) {
        if (x<10 || (x%10==0 && x!=0))
        {
            return false;
        }
        int ret = 0;
        while(x>ret)
        {
            ret = ret *10+ret%10;
            x/=10;
        }
        return x==ret || ret/10;
    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        int div=1;

        while(x>0){

            if(x/div>=10){
                div*=10;
            } else{
                int left = x/div;
                int right = x%10;
                if (left != right)
                {
                    return false;
                }
                x=(x%div)/10;
                div/=100;
            }

        }
        return true;
    }
};
int main() {
    int x;
    cin>>x;
//    Solution *s =new Solution;
//    cout<<s->isPalindrome(x)<<endl;
//
//    Solution1 *s1 =new Solution1;
//    cout<<s1->isPalindrome(x)<<endl;

    Solution2 *s2 =new Solution2;
    cout<<s2->isPalindrome(x)<<endl;
    return 0;
}