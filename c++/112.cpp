#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root){
            return false;
        }
        stack<TreeNode *> st{{root}};
        while (!st.empty()){
            TreeNode *t = st.top();
            st.pop();//出栈
            if (!t->left&&!t->right){
                if (t->val == sum){
                    return true;
                }
            }
            if (t->left){//将左子树加入栈
                t->left->val+=t->val;
                st.push(t->left);
            }
            if (t->right){//将右子树加入栈
                t->right->val+=t->val;
                st.push(t->right);
            }
        }
        return false;
    }
};
int main() {
    Solution *s = new Solution;
    return 0;
}