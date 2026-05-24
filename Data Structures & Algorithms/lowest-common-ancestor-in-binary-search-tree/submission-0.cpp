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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || p==nullptr || q==nullptr)
         return nullptr;
        if(p->val>q->val)
          return lowestCommonAncestor(root,q,p);
        if(p->val<=root->val && root->val<=q->val)
         return root;
        if(p->val>root->val)
         return lowestCommonAncestor(root->right,q,p);
        if(q->val<root->val)
         return lowestCommonAncestor(root->left,q,p);
        return nullptr; 
    }
};
