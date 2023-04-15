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
    bool auxiliar (TreeNode* no, int nivel, int& retorno) {
        if (!no)
            return true;
        // else
        int esq = nivel;
        int dir = nivel;
        bool ret = auxiliar (no->left, nivel + 1, esq) && auxiliar (no->right, nivel + 1, dir);
        retorno = max (esq, dir);
        return ret && (abs (esq - dir) < 2);
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) { // Precisa
            return true;
        }
        // else
        int esq = 0;
        int dir = 0;
        bool retorno = auxiliar (root->left, 1, esq) && auxiliar (root->right, 1, dir);
        return retorno && (abs (esq - dir) < 2);
    }
};

