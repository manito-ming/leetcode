#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size =nums.size();
        for (int i = 2; i < size; ++i) {
            if (nums[i-2] == nums[i]){
                for (int j = i; j < nums.size()-1; ++j) {
                    nums[j]=nums[j+1];
                }
                i--;
                size--;
            }
        }
        return size;
    }
};
int main() {
    Solution *s = new Solution;
    vector<int> vector1 = {1,1,1,2,2,3};
    cout<<s->removeDuplicates(vector1);
    return 0;
}