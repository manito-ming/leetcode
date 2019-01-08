#include <iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root!=NULL){
            int h1=maxDepth(root->right);
            int h2=maxDepth(root->left);
            return(h1>h2)?(h1+1):(h2+1);
        }
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}