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
    void find(TreeNode* root, int& ans, int max){
        if(!root) return;
        if(root->val>=max) {
            max = root-> val;
            ans++;
        }
        find(root->left,ans,max);
        find(root->right,ans,max);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        find(root,ans,-100);
        return ans;
    }
};
