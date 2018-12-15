#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int j =0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[j])//
            {
                nums[++j] = nums[i];//将数组相同的那个改变为下一个的数值
            }
        }
        return j+1;
    }
};
int main() {
    vector<int> vector1={1,1,2,2,3,3};
    Solution *s=new Solution;
    cout<<s->removeDuplicates(vector1);

    return 0;
}