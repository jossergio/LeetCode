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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> fila;
        int contar = 0;
        if (root) // Not nullptr
            fila.push (root);
        while (!fila.empty ()) {
            contar += 1;
            int tamanhoAtual = fila.size ();
            while (tamanhoAtual > 0) {
                TreeNode* tmp = fila.front ();
                fila.pop ();
                if (tmp->left) // Not nulptr
                    fila.push (tmp->left);
                if (tmp->right) // Not nullptr
                    fila.push (tmp->right);
                tamanhoAtual -= 1;
            }
        }
        return contar;
    }
};

