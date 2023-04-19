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

enum class Origem: int {ESQUERDA, DIREITA};

class Solution {
private:
    int buscar (TreeNode* no, int nivel, Origem origem) {
        // origem: 0- esquerda; 1- direita
        if (origem == Origem::ESQUERDA) {
            if (no->right)
                nivel = buscar (no->right, nivel + 1, Origem::DIREITA);
            if (no->left)
                nivel = max (nivel, buscar (no->left, 1, Origem::ESQUERDA)); // Recomeça a contagem
        } else { // Só pode ser Origem::DIREITA
            if (no->left)
                nivel = buscar (no->left, nivel + 1, Origem::ESQUERDA);
            if (no->right)
                nivel = max (nivel, buscar (no->right, 1, Origem::DIREITA));
        }
        return nivel;
    }
public:
    int longestZigZag(TreeNode* root) {
        // root nunca vem nullptr
        int maximo = 0;
        if (root->left)
            maximo = buscar (root->left, 1, Origem::ESQUERDA);
        if (root->right)
            maximo = max (maximo, buscar (root->right, 1, Origem::DIREITA));
        return maximo;
    }
};

