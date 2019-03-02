#include <iostream>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int numa = a.size(),numb = b.size();
        string str = "";
        int temp,sum=0;//temp为二进制数相加的和，sum是进位
        int n = max(numa,numb);
        //先将两个数组变为等大
        if (numa > numb){
            for (int i = 0; i < numa - numb; ++i) {
                b.insert(b.begin(),'0');
            }
        } else{
            for (int i = 0; i < numb - numa; ++i) {
                a.insert(a.begin(),'0');
            }
        }

        for (int j = n-1; j >=0; j--) {
             temp = (a[j]-'0')+(b[j] - '0')+sum;
             if (temp == 0 ){
                 str.insert(str.begin(),'0');
                 sum  = 0;
             } else if (temp == 1){
                 str.insert(str.begin(),'1');
                 sum = 0;
             }else if (temp == 2){
                 str.insert(str.begin(),'0');
                 sum = 1;
             }else if (temp == 3){
                 str.insert(str.begin(),'1');
                 sum = 1;
             }

        }
        //最后将进位１加上
        if (sum == 1){
            str.insert(str.begin(),'1');
        }
        return str;
    }
};
int main() {
    Solution *s=new Solution;
    string a = "1010",b = "1011";
    cout<<(*s).addBinary(a,b)<<endl;
    return 0;
}