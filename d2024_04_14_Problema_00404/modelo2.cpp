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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> fila;
        if (root != nullptr)
            fila.push (root);
        int resposta = 0;
        while (!fila.empty ()) {
            int c = fila.size ();
            while (c > 0) {
                c -= 1;
                TreeNode* tmp = fila.front ();
                fila.pop ();
                if (tmp->left != nullptr) {
                    fila.push (tmp->left);
                    if (tmp->left->left == nullptr && tmp->left->right == nullptr)
                        resposta += tmp->left->val;
                }
                if (tmp->right != nullptr)
                    fila.push (tmp->right);
            }
        }
        return resposta;
    }
};

