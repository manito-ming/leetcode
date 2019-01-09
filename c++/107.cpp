#include <iostream>
#include <vector>
#include <queue>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        if (!root)
        {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            vector<int> p;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode*node = q.front();
                q.pop();
                p.push_back(node->val);
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }

            }
            res.insert(res.begin(),p);
        }
        return res;
    }
};
int main() {
   
    return 0;
}
