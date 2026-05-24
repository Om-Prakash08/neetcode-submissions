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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N,";
        string s=to_string(root->val);
        s+=',';
        s+=serialize(root->left);
        s+=serialize(root->right);
        return s;
    }
    
    TreeNode* deserialize(string data, int &i){
        if(i>=data.size() || data[i]=='N') {
            i+=2;
            return nullptr;
        }
        int size = 1;
        while(i+size<data.size()&&data[i+size]!=','){
            size++;
        }
        TreeNode* root = new TreeNode(stoi(data.substr(i,size)));
        i+=size+1;
        root-> left = deserialize(data,i);
        root-> right = deserialize(data,i);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserialize(data,index);
    }
};
