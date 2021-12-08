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
    TreeNode *preparar (TreeNode *no) {
// Faz ajustes na árvore, para cada nó conter a soma de cada sub-árvore
// Cria, em paralelo, uma árvore de tilts, e a retorna
        if (no != nullptr) { // Só para garantir
            TreeNode *tmpNo = new TreeNode (); // Irá retornar esse elemento, que conterá o tilt de no
            int tmpValor = no->val; // Guardará a soma da subárvore, para alterar o nó, ao final
            int tilt = 0; // Inicia
            if (no->left != nullptr) {
                tmpNo->left = preparar (no->left);
                tmpValor += no->left->val;
                tilt += no->left->val; // A essa altura, conterá a soma da sub-árvore
            }
            if (no->right != nullptr) {
                tmpNo->right = preparar (no->right);
                tmpValor += no->right->val;
                tilt -= no->right->val; // A essa altura, conterá a soma da sub-árvore
            }
            no->val = tmpValor; // Ajusta o nó para conter a soma de sua sub-árvore
            tmpNo->val = abs (tilt);
            return tmpNo;
        }
        return nullptr; // Só para garantir
    } // *preparar
    
    int somarTilts (TreeNode *arvore) {
        if (arvore != nullptr)
            return (arvore->val + somarTilts (arvore->left) + somarTilts (arvore->right));
        return 0;
    } // somaTilts
    
public:
    int findTilt(TreeNode* root) {
        if (root != nullptr) {
            TreeNode *tmp = preparar (root);
            return somarTilts (tmp);
        }
        return 0; // Qualquer outra opção retornará isso
    }
};

