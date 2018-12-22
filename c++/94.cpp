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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        inorder(root,vec);
        return vec;
    }
    void inorder(TreeNode* root,vector<int> &vec) {
        if(root){
            inorder(root->left,vec);
            vec.push_back(root->val);
            inorder(root->right,vec);
        }
    }
};
