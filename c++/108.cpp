#include <iostream>
#include <vector>

using namespace std;
 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return sortedArrayToBST(nums,0,nums.size()-1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums,int left ,int right) {
        if (left > right){
            return NULL;
        }
        int mid = (left + right) / 2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = sortedArrayToBST(nums, left, mid - 1);
        cur->right = sortedArrayToBST(nums, mid + 1, right);
        return cur;
    }
    //中序遍历
    void InOrder(TreeNode *cur){
        if (cur){
            InOrder(cur->left);
            cout<<cur->val<<" ";
            InOrder(cur->right);
        }
    }
};

int main() {
    vector<int> vec = {-10,-3,0,5,9};
    Solution *s =new Solution;
    TreeNode *cur = s->sortedArrayToBST(vec);
    s->InOrder(cur);
    return 0;
}