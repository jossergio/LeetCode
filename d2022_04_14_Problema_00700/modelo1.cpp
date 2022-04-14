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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root != nullptr) {
            if (root->val == val)
                return root;
            else {
                TreeNode *no;
                if ((no = searchBST (root->left, val)) != nullptr)
                    return no;
                else
                    return searchBST (root->right, val);
            }
        } // if root != nullptr
        
        return nullptr;
    }
};

