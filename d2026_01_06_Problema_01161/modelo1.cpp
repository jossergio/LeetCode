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
    int maxLevelSum(TreeNode* root) {
        int nivel = 1; // root
        int resposta = 1; // Sempre há root
        int maior = root->val; // Já vimos que root é referência
        queue<TreeNode*> fila;
        fila.push (root);
        while (!fila.empty ()) {
            int t = fila.size ();
            int atual = 0; // Soma do nível atual
            for (int i = 0; i < t; i += 1) {
                TreeNode* tmp = fila.front ();
                fila.pop ();
                atual += tmp->val;
                if (tmp->left != nullptr)
                    fila.push (tmp->left);
                if (tmp->right != nullptr)
                    fila.push (tmp->right);
            }
            if (atual > maior) {
                resposta = nivel;
                maior = atual;
            }
            nivel += 1;
        }
        return resposta;
    }
};
