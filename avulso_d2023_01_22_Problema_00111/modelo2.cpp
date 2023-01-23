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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right) // Folha
            return 1;
        if (!root->left) // Não há nó à esquerda; independe do outro
            return 1 + minDepth (root->right);
        if (!root->right) // Não há nó à direita
            return 1 + minDepth (root->left);
        return 1 + min (minDepth (root->left), minDepth (root->right));
    }
};

