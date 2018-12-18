#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0],Sum=0;
        for (int num:nums)
        {
            Sum = max(Sum+num,num);
            result = max(Sum,result);
        }
        return result;
    }
};
int main() {
    vector<int> nums ={-2,1,-3,4,-1,2,1,-5,4};
    Solution *s = new Solution;
    cout<<s->maxSubArray(nums);
    return 0;
}