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
    TreeNode* processar (TreeNode* no) {
        if (no) {
            TreeNode* tmpDireito = no->right;
            no->right = processar (no->left);
            no->left = nullptr;
            TreeNode* tmp = no;
            while (tmp->right)
                tmp = tmp->right;
            tmp->right = processar (tmpDireito);
        }
        return no;
    }
public:
    void flatten(TreeNode* root) {
        root = processar (root);
    }
};

