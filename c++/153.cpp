#include <iostream>
#include <vector>

using namespace std;
//简单粗暴的全遍历
class Solution {
public:
    int findMin(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i]<nums[i+1]){
                int temp = nums[i+1];
                nums[i+1] = nums[i];
                nums[i] = temp;
            }
        }
        return nums[nums.size()-1];
    }
};
//练习一下二分查找法
class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        if (nums[left]<=nums[right]){
            return nums[left];
        } else {
            while (left != right - 1) {
                mid = (left + right) / 2;
                if (nums[mid] > nums[right]) {
                    left = mid;
                } else if (nums[mid] < nums[left]) {
                    right = mid;
                }

            }
           if (nums[left]>nums[right]){
               return nums[right];
           } else {
               return nums[left];
           }
        }
    }
};
int main() {
    vector<int> nums={2,1};
    Solution1 *s = new Solution1;
    cout<<s->findMin(nums);

    return 0;
}