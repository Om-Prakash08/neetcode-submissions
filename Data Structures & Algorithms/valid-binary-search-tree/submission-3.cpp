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
    bool isValidBST(TreeNode* root,int l,int r){
        if(!root) return true;
        if(root->val<=l || root->val>=r) return false;
        return isValidBST(root->left,l,root->val)&&isValidBST(root->right,root->val,r);
    }
    bool isValidBST(TreeNode* root) {
         return isValidBST(root,INT_MIN,INT_MAX);
    }
};
