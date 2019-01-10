#include <iostream>
#include <vector>
#include <stack>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  //要求不能使用递归就很烦了
  class Solution {
  public:
      vector<int> preorderTraversal(TreeNode* root) {
          if (!root) return {};
          vector<int> res;
          stack<TreeNode*> s{{root}};
          while (!s.empty()) {
              TreeNode *t = s.top(); s.pop();
              res.push_back(t->val);
              if (t->right) s.push(t->right);
              if (t->left) s.push(t->left);
          }
          return res;
      }
  };
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}