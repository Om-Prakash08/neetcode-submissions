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
    bool isValidBST(TreeNode* root,int &a){
        if(!root) return true;
        if(isValidBST(root->left,a)==false) return false;
        if(a>=root->val) return false;
        a = root->val;
        if(isValidBST(root->right,a)==false) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
         int a=INT_MIN;
         return isValidBST(root,a);
    }
};
