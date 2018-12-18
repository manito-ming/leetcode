#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != target)
            {
                if (nums[j] < target )
                {
                    ++j;
                }
            } else{
                return i;
            }
        }
        return j;

    }
};

int main() {
    Solution *s  =new Solution;
    vector<int> nums ={1,3,5,6};
    int target = 2;
    cout<<s->searchInsert(nums,target);
    return 0;
}