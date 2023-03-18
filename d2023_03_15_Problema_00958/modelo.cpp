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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> fila;
        bool final = false;
        fila.push (root); // Pela definição do problema, nunca é vazia
        int nivel = 1;
        while (!fila.empty ()) {
            int t = fila.size ();
            for (int i = 0; i < t; i += 1) {
                TreeNode* tmp = fila.front ();
                fila.pop ();
                if (tmp->left) { // not nullptr
                    if (final)
                        return false;
                    else
                        fila.push (tmp->left);
                } else
                    final = true;
                if (tmp->right) { // not nullptr
                    if (final) // Há nó à direita sem o da esquerda
                        return false;
                    else
                        fila.push (tmp->right);
                } else {
                    final = true;
                }
            }
            nivel *= 2;
            final = fila.size () != nivel; // Preencheu todos esperados desse nível?
        }
        return true; // Se chegou até aqu, não viu erro
    }
};

