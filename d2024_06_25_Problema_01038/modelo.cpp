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
    void buscar (int& acumulado, TreeNode* no) {
        if (no->right != nullptr) {
            buscar (acumulado, no->right);
        }
        acumulado += no->val;
        no->val = acumulado;
        if (no->left != nullptr) {
            buscar (acumulado, no->left);
        }
   }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int acumulado = 0;
        buscar (acumulado, root);
        return root;
    }
};

