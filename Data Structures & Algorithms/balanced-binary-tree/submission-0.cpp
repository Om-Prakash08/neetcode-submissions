/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root, int &h)
    {
        if(root==nullptr)
          return true;
        int lh = 0;
        int rh = 0;
        if(isBalanced(root->left,lh)&&isBalanced(root->right,rh)){
           if(abs(lh-rh)>1)
             return false;
           h = 1 + max(lh,rh);
           return true;
        } 
        return false;
    }
    bool isBalanced(TreeNode* root) {
        int a =0;
        return isBalanced(root,a);
    }
};
