class Solution {
public:
    unordered_map<int, int> mp;

    TreeNode* build(vector<int>& preorder, int l, int r,
                    vector<int>& inorder, int x, int y) {
        if (l > r || x > y) return nullptr;

        TreeNode* root = new TreeNode(preorder[l]);

        int j = mp[preorder[l]];   // O(1) lookup
        int leftSize = j - x;

        root->left = build(preorder, l + 1, l + leftSize,
                           inorder, x, j - 1);

        root->right = build(preorder, l + leftSize + 1, r,
                            inorder, j + 1, y);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }
};