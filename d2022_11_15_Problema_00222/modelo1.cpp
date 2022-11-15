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
    int countNodes(TreeNode* root) {
        if (!root) // nullptr
            return 0;
        int contar = 0;
        queue<TreeNode*> fila;
        fila.push (root);
        while (!fila.empty ()) {
            contar += fila.size ();
            int contadorAtual = fila.size ();
            for (; contadorAtual > 0; contadorAtual--) {
                // Esse algoritmo salta um nível, apesar de contá-lo, tentado ser menor que O (n)
                TreeNode* atual = fila.front ();
                fila.pop ();
                if (atual->left) {
                    contar += 1;
                    if (atual->left->left)
                        fila.push (atual->left->left);
                    if (atual->left->right)
                        fila.push (atual->left->right);
                }
                if (atual->right) {
                    contar += 1;
                    if (atual->right->left)
                        fila.push (atual->right->left);
                    if (atual->right->right)
                        fila.push (atual->right->right);
                }
            }
        }
        return contar;
    }
};

