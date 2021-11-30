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
    TreeNode *pegarLimiteDireita (TreeNode *anterior, TreeNode *no) {
    // Algoritmo recursivo. Só para manter o conceito geral
        if (no == nullptr) // Só se for o imediado (na esquerda do nó que será retirado)
            return nullptr;
        else { // if no == nullptr
            if (no->right == nullptr) {
                if (anterior != nullptr) // É o primeiro da sequência
                    anterior->right = no->left;
                return no;
            } else { // if no->right == nullptr
                return pegarLimiteDireita (no, no->right);
            } // else if no->right == nullptr
        } // else if no == nullptr
    } // pegarLimiteDireita

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) // Por definição, nunca virá. Só para garantir.
            return root;
        if (root->val == key) {
            TreeNode *tmp; // Não precisa inicializar aqui
            if (root->left == nullptr) { // Não há nó do lado esquerdo; joga direita
                tmp = root->right; // Indiferente se é nullptr
            } else { // if root->left == nullptr
                tmp = pegarLimiteDireita (nullptr, root->left); // Se chegou aqui, root->left não é nullptr
                if (tmp != root->left)
                    tmp->left = root->left;
                tmp->right = root->right;
            } // else if root->left == nullptr
            delete root;
            root = tmp;
        } else { // if root->val == key
            if (root->val > key)
                root->left = deleteNode (root->left, key);
            else
                root->right = deleteNode (root->right, key);
        }
        return root;
    }
};

