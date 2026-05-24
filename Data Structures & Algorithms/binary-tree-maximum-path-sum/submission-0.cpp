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
    int maxPathSum(TreeNode* root, int &ans){
        if(!root) return 0;
        int l = maxPathSum(root->left,ans);
        int r = maxPathSum(root->right,ans);
        ans = max(ans,root->val+max(l,0)+max(r,0));
        return root->val + max(max(l,r),0);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxPathSum(root,ans);
        return ans;
    }
};
