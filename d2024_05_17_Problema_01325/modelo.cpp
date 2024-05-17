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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr || (root->val == target && root->left == nullptr && root->right == nullptr))
            return nullptr;
        root->left = removeLeafNodes (root->left, target);
        root->right = removeLeafNodes (root->right, target);
        if (root->val == target && root->left == nullptr && root->right == nullptr) // Precisamos dessa redundância, pois o nós pode ter virado folha
            return nullptr;
        return root;
    }
};

