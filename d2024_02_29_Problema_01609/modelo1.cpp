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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> fila;
        bool par = false; // A prineira linha é ímpar; será usada para ambas
        fila.push (root); // Semore há um, pela definição do problema
        while (!fila.empty ()) {
            int t = fila.size ();
            TreeNode* atual = fila.front ();
            fila.pop ();
            t -= 1; // A cada pop na fila
            // Primeiro teste
            if ((atual->val % 2 == 0) != par)
                return false;
            if (atual->left != nullptr)
                fila.push (atual->left);
            if (atual->right != nullptr)
                fila.push (atual->right);
            while (t > 0) {
                TreeNode* proximo = fila.front ();
                fila.pop ();
                t -= 1;
                // Primeiro teste do próximo
                if ((proximo->val % 2 == 0) != par)
                    return false;
                if (atual->val == proximo->val || ((atual->val > proximo->val) != par))
                    return false;
                if (proximo->left != nullptr)
                    fila.push (proximo->left);
                if (proximo->right != nullptr)
                    fila.push (proximo->right);
                atual = proximo;
            }
            par = !par; // Inverte
        }
        return true; // Passou por tudo
    }
};

