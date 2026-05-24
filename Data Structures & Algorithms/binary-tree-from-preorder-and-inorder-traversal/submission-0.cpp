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
    TreeNode* build(vector<int>& preorder, int l, int r, vector<int>& inorder, int x, int y){
       if(l>r || x>y) return nullptr;
       TreeNode* root = new TreeNode(preorder[l]);
       int i = l;
       int j = x;
       while(inorder[j]!=preorder[l]){
        j++;
        i++;
       }
       root -> left = build(preorder,l+1,i,inorder,x,j-1);
       root -> right = build(preorder,i+1,r,inorder,j+1,y);
       return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};
