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
private:
    bool temUm (TreeNode *t) {
        if (t != nullptr)
            if (t->val == 1)
                return true;
            else
                return temUm (t->left) | temUm (t->right);
        return false;
    } // temUm
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root != nullptr) {
            if (!temUm (root->left))
                root->left = nullptr; // Não tem otimização de memória. É um desafio!
            else
                root->left = pruneTree (root->left);
            if (!temUm (root->right))
                root->right = nullptr; // Idem.
            else
                root->right = pruneTree (root->right);
            if (root->val == 0 && root->left == nullptr && root->right == nullptr)
                root = nullptr;
        } // if root != nullptr
        return root; // É lógico!
    } // pruneTree
};

