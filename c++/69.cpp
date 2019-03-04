#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right =x;
        if (x<=1){
            return x;
        }
        int mid = 0;
        while (left<right){
            int mid =left+ (right-left)/2;
            if (x/mid>=mid){
                left = mid+1;
            } else{
                right = mid;
            }
        }
        return right-1;
    }
};

int main() {
    Solution *s = new Solution;
    int x = 25;
    cout<<(*s).mySqrt(x);
    return 0;
}