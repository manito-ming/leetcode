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
    vector<vector<int>> levelOrder(TreeNode* root) {
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
                TreeNode *node = q.front();//将队首放入node
                q.pop();//把q里面的东西拿出去
                p.push_back(node->val);//将这个数据加在队列的尾部
                if (node->left){
                    q.push(node->left);
                }
                if (node->right){
                    q.push(node->right);
                }

            }
            res.push_back(p);//遍历完每一层后就将这一层的数组放在最后
        }
        return res;
    }
};
int main() {

    return 0;
}