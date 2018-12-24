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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0){
            return {};
        }
        return *generateTreesDFS(1,n);
    }
    //开始建立二叉树并存储在数组中
    vector<TreeNode*> *generateTreesDFS(int start, int end){
        vector<TreeNode*> *subTree = new vector<TreeNode*>();//建立存储二叉树的数组
        if (start > end){
            subTree->push_back(NULL);
        } else{
            for (int i = start; i <=end; ++i) {
                vector<TreeNode*> *leftSubTree =generateTreesDFS(start,i-1);
                vector<TreeNode*> *rightSUbTree = generateTreesDFS(i+1,end);
                //下面是建立二叉树并存放在subTress数组中
                for (int j = 0; j < leftSubTree->size(); ++j) {
                    for (int k = 0; k < rightSUbTree->size(); ++k) {
                        TreeNode * node =new TreeNode(i);
                        node->left=(*leftSubTree)[j];
                        node->right=(*rightSUbTree)[k];
                        subTree->push_back(node);
                    }
                }
            }
        }
        return subTree;
    }
    //层序遍历
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
    Solution *s=new Solution;
    int n = 3;
    vector<TreeNode*> t = s->generateTrees(n);
    //遍历数组
    for (int i = 0; i < t.size(); ++i) {
        //遍历二叉树打印输出
        vector<vector<int>> vector1 =   s->levelOrder(t[i]);
        for (int i = 0; i < vector1.size(); ++i) {
            for (int j = 0; j < vector1[i].size(); ++j) {
                cout<<vector1[i][j]<<"\t";
            }

        }
        cout<<endl;

    }

    return 0;
}