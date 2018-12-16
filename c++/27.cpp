#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
        {
            return 0;
        }
        int j = 0; int n = nums.size();
        for (int i = 0; i < n; ++i) {

            if (nums[i] != val)
            {
                nums[j] = nums[i];
                cout<<nums[j];
                j++;

            }
        }
        cout<<endl;
        return j;
    }
};
int main() {
    vector<int> vector1={1,1,2,2,3,3};
    Solution *s=new Solution;
    cout<<s->removeElement(vector1,1);

    return 0;
}